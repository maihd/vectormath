#pragma once

#include <stdint.h>

struct ThreadMutex
{
    char            internal[40];

    void            Create(void);
    void            Destroy(void);

    void            Lock(void);
    void            Unlock(void);
    bool            TryLock(void);
};

struct ThreadSignal
{
    char            internal[8];

    void            Create(void);
    void            Destroy();

    void            Wait(const ThreadMutex& mutex);
    void            Signal(void);
    void            Broadcast(void);
};

struct ThreadSemaphore
{
    int             count;
    ThreadMutex     mutex;
    ThreadSignal    signal;

    void            Create(int value);
    void            Destroy();

    void            Post(void);
    void            Wait(void);
    bool            TryWait(void);
};

typedef int (ThreadFunc)(void*);

struct ThreadDesc
{
    uint32_t        id;
    uintptr_t       handle;

    //void*           stack;
    //const char*     name;
    //int32_t         preferedCore;
    //int32_t         migrateEnabled;

    ThreadFunc*     func;
    void*           data;
};

#ifdef __cplusplus
extern "C" {
#endif

void        Thread_Setup();
void        Thread_Shutdown();
bool        Thread_IsMainThread();
uint32_t    Thread_GetMainThreadId();

int         Thread_GetCpuCores();
int64_t     Thread_GetCpuTicks();
int64_t     Thread_GetCpuFrequency();

void        Thread_Sleep(int64_t miliseconds);
void        Thread_MicroSleep(int64_t microseconds);

bool        Thread_Run(ThreadFunc* func, void* data, ThreadDesc* outThreadDesc);
void        Thread_Join(ThreadDesc* threadDesc);

#ifdef __cplusplus
}
#endif
