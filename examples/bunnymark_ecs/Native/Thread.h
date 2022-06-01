#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

int64_t     Thread_GetCpuTicks();
int64_t     Thread_GetCpuFrequency();

void        Thread_MicroSleep(int64_t microseconds);

#ifdef __cplusplus
}
#endif
