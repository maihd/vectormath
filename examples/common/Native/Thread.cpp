#include <assert.h>

#define VC_EXTRALEAN
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "Thread.h"

static DWORD gMainThreadId;

void Thread_Setup()
{
    gMainThreadId = GetCurrentThreadId();
}

void Thread_Shutdown()
{
    assert(gMainThreadId == GetCurrentThreadId());

    gMainThreadId = 0;
}

bool Thread_IsMainThread()
{
    return gMainThreadId == GetCurrentThreadId();
}

uint32_t Thread_GetMainThreadId()
{
    return (uint32_t)gMainThreadId;
}

int Thread_GetCpuCores()
{
    _SYSTEM_INFO systemInfo;
    GetSystemInfo(&systemInfo);
    return systemInfo.dwNumberOfProcessors;
}

int64_t Thread_GetCpuTicks()
{
    LARGE_INTEGER value;
    return QueryPerformanceCounter(&value) ? (int64_t)value.QuadPart : (int64_t)GetTickCount64();
}

int64_t Thread_GetCpuFrequency()
{
    static int64_t savedValue;
    if (savedValue > 0)
    {
        return savedValue;
    }

    LARGE_INTEGER value;
    return QueryPerformanceFrequency(&value) ? (savedValue = (int64_t)value.QuadPart) : (savedValue = 1000);
}

void Thread_Sleep(int64_t miliseconds)
{
    Sleep((DWORD)(miliseconds & MAXDWORD32));
}

void Thread_MicroSleep(int64_t microseconds)
{
    /* 'NTSTATUS NTAPI NtDelayExecution(BOOL Alerted, PLARGE_INTEGER time);' */
    /* 'typedef LONG NTSTATUS;' =)) */
    /* '#define NTAPI __stdcall' =)) */
    typedef LONG(__stdcall * NtDelayExecutionFN)(BOOL, PLARGE_INTEGER);
    
    static int done_finding;
    static NtDelayExecutionFN NtDelayExecution;
    
    if (!NtDelayExecution && !done_finding)
    {
        done_finding = 1;
        HMODULE module = GetModuleHandleA("ntdll.dll");
        const char* func = "NtDelayExecution";
        NtDelayExecution = (NtDelayExecutionFN)GetProcAddress(module, func);
    }
    
    if (NtDelayExecution)
    {
        LARGE_INTEGER times;
        times.QuadPart = (LONGLONG)(-microseconds * 10); // Timer is precise as 100 nanoseconds
        NtDelayExecution(FALSE, &times);
    }
    else
    {
        Sleep((DWORD)(microseconds / (1000)));
    }
}

bool Thread_Run(ThreadFunc* func, void* data, ThreadDesc* outThread)
{
    DWORD threadId;
    HANDLE threadHandle = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)func, data, 0, &threadId);

    if (outThread)
    {
        outThread->id = (uint32_t)threadId;
        outThread->func = func;
        outThread->data = data;
        outThread->handle = (uintptr_t)threadHandle;
    }

    return threadHandle != NULL;
}

void Thread_Join(ThreadDesc* thread)
{
    HANDLE threadHandle = thread ? (HANDLE)thread->handle : GetCurrentThread();
    WaitForSingleObject(threadHandle, INFINITE);
    CloseHandle(threadHandle);

    if (thread)
    {
        thread->id = 0;
        thread->handle = 0;
    }
}

void ThreadMutex::Init(void)
{
    ::InitializeCriticalSection((LPCRITICAL_SECTION)this);
}

void ThreadMutex::Release(void)
{
    ::DeleteCriticalSection((LPCRITICAL_SECTION)this);
}

void ThreadMutex::Lock(void)
{
    ::EnterCriticalSection((LPCRITICAL_SECTION)this);
}

void ThreadMutex::Unlock(void)
{
    ::LeaveCriticalSection((LPCRITICAL_SECTION)this);
}

bool ThreadMutex::TryLock(void)
{
    return ::TryEnterCriticalSection((LPCRITICAL_SECTION)this);
}

void ThreadSignal::Init(void)
{
    ::InitializeConditionVariable((CONDITION_VARIABLE*)this);
}

void ThreadSignal::Release(void)
{
}

void ThreadSignal::Wait(const ThreadMutex& mutex)
{
    if (::SleepConditionVariableCS((CONDITION_VARIABLE*)this, (CRITICAL_SECTION*)&mutex, INFINITE))
    {
        //process::abort();
    }
}

void ThreadSignal::Signal(void)
{
    ::WakeConditionVariable((CONDITION_VARIABLE*)this);
}

void ThreadSignal::Broadcast(void)
{
    ::WakeAllConditionVariable((CONDITION_VARIABLE*)this);
}

void ThreadSemaphore::Init(int count)
{
    this->count = count;
    this->mutex.Init();
    this->signal.Init();
}

void ThreadSemaphore::Release()
{
    this->count = 0;
    this->mutex.Release();
    this->signal.Release();
}

void ThreadSemaphore::Post(void)
{
    mutex.Lock();

    while (count == 1)
    {
        signal.Wait(mutex);
    }
    count++;

    mutex.Unlock();
}

void ThreadSemaphore::Wait(void)
{
    mutex.Lock();

    while (count <= 0)
    {
        signal.Wait(mutex);
    }
    count--;

    mutex.Unlock();
}

bool ThreadSemaphore::TryWait(void)
{
    if (!mutex.TryLock())
        return false;

    if (count == 0)
    {
        mutex.Unlock();
        return false;
    }

    count--;
    mutex.Unlock();

    return true;
}
