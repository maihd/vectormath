#pragma once

#include <stdint.h>

#ifndef __cplusplus
#include <stdbool.h>
#endif

typedef struct ThreadMutex
{
    char                internal[40];
} ThreadMutex;

typedef struct ThreadSignal
{
    char                internal[8];
} ThreadSignal;

typedef struct ThreadSemaphore
{
    int32_t             count;
    ThreadMutex         mutex;
    ThreadSignal        signal;
} ThreadSemaphore;

typedef int32_t     (ThreadFunc)(void*);
typedef void        (ThreadFiberFunc)(void*);

typedef struct ThreadDesc
{
    uint32_t            id;
    uintptr_t           handle;
    uintptr_t           fiberHandle;

    //void*           stack;
    //const char*     name;
    //int32_t         preferedCore;
    //int32_t         migrateEnabled;

    ThreadFunc*         func;
    void*               data;
} ThreadDesc;

typedef struct ThreadFiber
{
    uintptr_t           handle;

    ThreadFiberFunc*    func;
    void*               data;
} ThreadFiber;

#ifdef __cplusplus
extern "C" {
#endif

void        Thread_Setup();
void        Thread_Shutdown();

bool        Thread_IsMainThread();
uint32_t    Thread_GetMainThreadId();

//bool        Thread_IsMainFiber(const ThreadDesc* thread);
//uint32_t    Thread_GetMainFiberId(const ThreadDesc* thread);

int32_t     Thread_GetCpuCores();
int64_t     Thread_GetCpuTicks();
int64_t     Thread_GetCpuFrequency();

void        Thread_Sleep(int64_t miliseconds);
void        Thread_MicroSleep(int64_t microseconds);

bool        Thread_Run(ThreadFunc* func, void* data, ThreadDesc* outThreadDesc);
void        Thread_Join(ThreadDesc* threadDesc);

void        ThreadMutex_Create(ThreadMutex* mutex);
void        ThreadMutex_Destroy(ThreadMutex* mutex);

void        ThreadMutex_Lock(ThreadMutex* mutex);
void        ThreadMutex_Unlock(ThreadMutex* mutex);
bool        ThreadMutex_TryLock(ThreadMutex* mutex);

void        ThreadSignal_Create(ThreadSignal* signal);
void        ThreadSignal_Destroy(ThreadSignal* signal);

void        ThreadSignal_Wait(ThreadSignal* signal, const ThreadMutex* mutex);
void        ThreadSignal_Signal(ThreadSignal* signal);
void        ThreadSignal_Broadcast(ThreadSignal* signal);

void        ThreadSemaphore_Create(ThreadSignal* signal, int32_t value);
void        ThreadSemaphore_Destroy(ThreadSignal* signal);

void        ThreadSemaphore_Post(void);
void        ThreadSemaphore_Wait(void);
bool        ThreadSemaphore_TryWait(void);

void        ThreadFiber_Create(ThreadFiber* fiber);
void        ThreadFiber_Destroy(ThreadFiber* fiber);
void        ThreadFiber_SwitchTo(ThreadFiber* fiber);

#ifdef __cplusplus
}
#endif
