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
typedef struct Job
{
    JobFunc*        func;
    void*           data;
} Job;

/// The job system for parallel computing. The workers donot steal job.
/// The JobSystem must be alive long enough before worker threads done,
/// should allocate JobSystem's memory in global/static scope, main() function, or heap.
typedef struct JobSystem
{
    ThreadDesc      workerThreads[JOB_SYSTEM_MAX_WORKERS];                  // Workers' thread description

    Job             jobs[JOB_SYSTEM_MAX_WORKERS][JOB_SYSTEM_MAX_JOBS];      // Jobs ring buffer
    int32_t         queueIndex[JOB_SYSTEM_MAX_WORKERS];                     // Safe index to queue a new job
    int32_t         runningIndex[JOB_SYSTEM_MAX_WORKERS];                   // The current running job
    int32_t         currentWorkerIndex;                                     // Find out which worker receive the job

    ThreadMutex     mutex;
    ThreadSignal    idleSignal;
    ThreadSignal    queueSignal;

    int32_t         workerCount;
    int32_t         idleWorkerCount;

    volatile bool   running;
} JobSystem;

#ifdef __cplusplus
extern "C" {
#endif

void                JobSystem_Create(JobSystem* jobSystem, int32_t requestWorkers);
void                JobSystem_Destroy(JobSystem* jobSystem);

bool                JobSystem_IsIdle(JobSystem* jobSystem);
void                JobSystem_WaitIdle(JobSystem* jobSystem);

void                JobSystem_QueueJob(JobSystem* jobSystem, JobFunc* func, void* items);

#ifdef __cplusplus
}
#endif
