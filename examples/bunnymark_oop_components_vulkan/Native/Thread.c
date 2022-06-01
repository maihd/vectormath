#include "Thread.h"

#if _WIN32
#   define VC_EXTRALEAN
#   define WIN32_LEAN_AND_MEAN
#   include <Windows.h>
#else
#   include <unistd.h>
#endif

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

void Thread_MicroSleep(int64_t microseconds)
{
#if _WIN32
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
#else
    usleep((useconds_t)microseconds);
#endif
}
