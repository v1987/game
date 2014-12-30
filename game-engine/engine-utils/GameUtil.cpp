#include "GameUtil.h"

VOID MySleep(UINT millionseconds) {
#if defined(__WINDOWS__)
    Sleep(millionseconds);
#elif defined(__LINUX__)
    usleep(millionseconds * 1000);
#endif
}

TID MyGetCurrentThreadID() {
#if defined(__WINDOWS__)
    return GetCurrentThreadId();
#elif defined(__LINUX__)
    return pthread_self();
#endif
}

CHAR* MySocketError() {
#ifndef _ESIZE
#define _ESIZE 256
#endif

    extern CHAR Error[_ESIZE];
    return Error;
}

