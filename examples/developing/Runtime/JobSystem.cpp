#include "JobSystem.h"

#include <VectorMath.h>

static int JobSystem_ThreadFunc(void* data);

void JobSystem_Create(JobSystem* jobSystem, int requestWorkers)
{
    const int threadCount = max(1, Thread_GetCpuCores());
    const int workerCount = requestWorkers <= 0 ? threadCount : min(threadCount, min(requestWorkers, JOB_SYSTEM_MAX_WORKERS));

    jobSystem->mutex.Init();
    jobSystem->idleSignal.Init();
    jobSystem->queueSignal.Init();

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
    jobSystem->mutex.Lock();
    jobSystem->running = false;
    jobSystem->mutex.Unlock();

    jobSystem->queueSignal.Broadcast();

    for (int i = 0, n = jobSystem->workerCount; i < n; i++)
    {
        jobSystem->queueIndex[i] = 0;
        jobSystem->runningIndex[i] = 0;
        Thread_Join(&jobSystem->workerThreads[i]);
    }

    jobSystem->queueSignal.Release();
    jobSystem->idleSignal.Release();
    jobSystem->mutex.Release();
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
    jobSystem->mutex.Lock();
    
    const bool isIdle = JobSystem_IsIdle_NonLocking(jobSystem);

    jobSystem->mutex.Unlock();
    return isIdle;
}

void JobSystem_WaitIdle(JobSystem* jobSystem)
{
    jobSystem->mutex.Lock();

    while (!JobSystem_IsIdle_NonLocking(jobSystem))
    {
        jobSystem->idleSignal.Wait(jobSystem->mutex);
    }

    jobSystem->mutex.Unlock();
}

void JobSystem_QueueJob(JobSystem* jobSystem, JobFunc* func, void* items)
{
    jobSystem->mutex.Lock();

    const int workerIndex = jobSystem->currentWorkerIndex;

    Job* jobs = jobSystem->jobs[workerIndex];
    int* queueIndex = &jobSystem->queueIndex[workerIndex];

    jobs[*queueIndex] = Job{ func, items };
    *queueIndex = (*queueIndex + 1) % JOB_SYSTEM_MAX_JOBS;

    jobSystem->currentWorkerIndex = (workerIndex + 1) % jobSystem->workerCount;

    jobSystem->mutex.Unlock();

    jobSystem->queueSignal.Broadcast();
}

int JobSystem_ThreadFunc(void* data)
{
    JobSystem* jobSystem = (JobSystem*)data;

    jobSystem->mutex.Lock();
    
    const int workerIndex = jobSystem->currentWorkerIndex;

    Job* jobs = jobSystem->jobs[workerIndex];
    int* queueIndex = &jobSystem->queueIndex[workerIndex];
    int* runningIndex = &jobSystem->runningIndex[workerIndex];

    jobSystem->currentWorkerIndex = (jobSystem->currentWorkerIndex + 1) % jobSystem->workerCount;
    jobSystem->mutex.Unlock();

    while (jobSystem->running)
    {
        jobSystem->mutex.Lock();

        jobSystem->idleWorkerCount++;
        while (jobSystem->running && *queueIndex == *runningIndex)
        {
            jobSystem->idleSignal.Broadcast();
            jobSystem->queueSignal.Wait(jobSystem->mutex);
        }
        jobSystem->idleWorkerCount--;
        jobSystem->mutex.Unlock();

        while (*queueIndex != *runningIndex)
        {
            jobSystem->mutex.Lock();
            Job job = jobs[*runningIndex];

            *runningIndex = (*runningIndex + 1) % JOB_SYSTEM_MAX_JOBS;

            jobSystem->mutex.Unlock();

            job.func(job.data);
        }
    }

    jobSystem->mutex.Lock();
    
    jobSystem->idleWorkerCount++;
    jobSystem->idleSignal.Broadcast();

    jobSystem->mutex.Unlock();

    return 0;
}
