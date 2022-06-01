#include "JobSystem.h"

#include <VectorMath.h>

static int JobSystem_ThreadFunc(void* data);

void JobSystem_Create(JobSystem* jobSystem, int32_t requestWorkers)
{
    const int threadCount = max(1, Thread_GetCpuCores());
    const int workerCount = requestWorkers <= 0 ? threadCount : min(threadCount, min(requestWorkers, JOB_SYSTEM_MAX_WORKERS));

    ThreadMutex_Create(&jobSystem->mutex);
    ThreadSignal_Create(&jobSystem->idleSignal);
    ThreadSignal_Create(&jobSystem->queueSignal);

    jobSystem->running = true;

    jobSystem->idleWorkerCount = 0;
    
    jobSystem->workerCount = workerCount;
    for (int i = 0; i < workerCount; i++)
    {
        jobSystem->queueIndex[i] = 0;
        jobSystem->runningIndex[i] = 0;
        Thread_Run(JobSystem_ThreadFunc, jobSystem, &jobSystem->workerThreads[i]);
    }

    JobSystem_WaitIdle(jobSystem);
}

void JobSystem_Destroy(JobSystem* jobSystem)
{
    ThreadMutex_Lock(&jobSystem->mutex);
    jobSystem->running = false;
    ThreadMutex_Unlock(&jobSystem->mutex);

    ThreadSignal_Broadcast(&jobSystem->queueSignal);

    for (int i = 0, n = jobSystem->workerCount; i < n; i++)
    {
        jobSystem->queueIndex[i] = 0;
        jobSystem->runningIndex[i] = 0;
        Thread_Join(&jobSystem->workerThreads[i]);
    }

    ThreadSignal_Destroy(&jobSystem->queueSignal);
    ThreadSignal_Destroy(&jobSystem->idleSignal);
    ThreadMutex_Destroy(&jobSystem->mutex);
}

static bool JobSystem_IsIdle_NonLocking(JobSystem* jobSystem)
{
    bool allWorkersIdle = true;
    for (int i = 0, n = jobSystem->workerCount; i < n; i++)
    {
        if (jobSystem->queueIndex[i] != jobSystem->runningIndex[i])
        {
            allWorkersIdle = false;
            break;
        }
    }

    return (allWorkersIdle && (jobSystem->idleWorkerCount == jobSystem->workerCount)) || !jobSystem->running;
}

bool JobSystem_IsIdle(JobSystem* jobSystem)
{
    ThreadMutex_Lock(&jobSystem->mutex);
    
    const bool isIdle = JobSystem_IsIdle_NonLocking(jobSystem);

    ThreadMutex_Unlock(&jobSystem->mutex);
    return isIdle;
}

void JobSystem_WaitIdle(JobSystem* jobSystem)
{
    ThreadMutex_Lock(&jobSystem->mutex);

    while (!JobSystem_IsIdle_NonLocking(jobSystem))
    {
        ThreadSignal_Wait(&jobSystem->idleSignal, &jobSystem->mutex);
    }

    ThreadMutex_Unlock(&jobSystem->mutex);
}

void JobSystem_QueueJob(JobSystem* jobSystem, JobFunc* func, void* items)
{
    ThreadMutex_Lock(&jobSystem->mutex);

    const int workerIndex = jobSystem->currentWorkerIndex;

    Job* jobs = jobSystem->jobs[workerIndex];
    int* queueIndex = &jobSystem->queueIndex[workerIndex];

    jobs[*queueIndex] = (Job){ func, items };
    *queueIndex = (*queueIndex + 1) % JOB_SYSTEM_MAX_JOBS;

    jobSystem->currentWorkerIndex = (workerIndex + 1) % jobSystem->workerCount;

    ThreadMutex_Unlock(&jobSystem->mutex);

    ThreadSignal_Broadcast(&jobSystem->queueSignal);
}

int JobSystem_ThreadFunc(void* data)
{
    JobSystem* jobSystem = (JobSystem*)data;

    ThreadMutex_Lock(&jobSystem->mutex);
    
    const int workerIndex = jobSystem->currentWorkerIndex;

    Job* jobs = jobSystem->jobs[workerIndex];
    int* queueIndex = &jobSystem->queueIndex[workerIndex];
    int* runningIndex = &jobSystem->runningIndex[workerIndex];

    jobSystem->currentWorkerIndex = (jobSystem->currentWorkerIndex + 1) % jobSystem->workerCount;
    ThreadMutex_Unlock(&jobSystem->mutex);

    while (jobSystem->running)
    {
        ThreadMutex_Lock(&jobSystem->mutex);

        jobSystem->idleWorkerCount++;
        while (jobSystem->running && *queueIndex == *runningIndex)
        {
            ThreadSignal_Broadcast(&jobSystem->idleSignal);
            ThreadSignal_Wait(&jobSystem->queueSignal, &jobSystem->mutex);
        }
        jobSystem->idleWorkerCount--;
        ThreadMutex_Unlock(&jobSystem->mutex);

        while (*queueIndex != *runningIndex)
        {
            ThreadMutex_Lock(&jobSystem->mutex);
            Job job = jobs[*runningIndex];

            *runningIndex = (*runningIndex + 1) % JOB_SYSTEM_MAX_JOBS;

            ThreadMutex_Unlock(&jobSystem->mutex);

            job.func(job.data);
        }
    }

    ThreadMutex_Lock(&jobSystem->mutex);
    
    jobSystem->idleWorkerCount++;
    ThreadSignal_Broadcast(&jobSystem->idleSignal);

    ThreadMutex_Unlock(&jobSystem->mutex);

    return 0;
}
