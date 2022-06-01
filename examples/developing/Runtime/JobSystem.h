#pragma once

#include <stdint.h>
#include "Native/Thread.h"

enum
{
    JOB_SYSTEM_MAX_WORKERS = 16,
    JOB_SYSTEM_MAX_JOBS = 32,
};

typedef void (JobFunc)(void* items);

/// This data structure only use for JobSystem
/// The members' data types we used based-on target host machine
struct Job
{
    JobFunc*        func;
    void*           data;
};

/// The job system for parallel computing. The workers donot steal job.
/// The JobSystem must be alive long enough before worker threads done,
/// should allocate JobSystem's memory in global/static scope, main() function, or heap.
/// The members' data types we used based-on target host machine
struct JobSystem
{
    ThreadDesc      workerThreads[JOB_SYSTEM_MAX_WORKERS];                  // Workers' thread description

    Job             jobs[JOB_SYSTEM_MAX_WORKERS][JOB_SYSTEM_MAX_JOBS];      // Jobs ring buffer
    int             queueIndex[JOB_SYSTEM_MAX_WORKERS];                     // Safe index to queue a new job
    int             runningIndex[JOB_SYSTEM_MAX_WORKERS];                   // The current running job
    int             currentWorkerIndex;                                     // Find out which worker receive the job

    ThreadMutex     mutex;
    ThreadSignal    idleSignal;
    ThreadSignal    queueSignal;

    int             workerCount;
    int             idleWorkerCount;

    volatile bool   running;
};

void                JobSystem_Create(JobSystem* jobSystem, int requestWorkers);
void                JobSystem_Destroy(JobSystem* jobSystem);

bool                JobSystem_IsIdle(JobSystem* jobSystem);
void                JobSystem_WaitIdle(JobSystem* jobSystem);

void                JobSystem_QueueJob(JobSystem* jobSystem, JobFunc* func, void* items);
