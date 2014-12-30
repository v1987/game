#include "Lock.h"

//共享锁
#if defined(__WINDOWS__)

Lock::Lock() {
    InitializeCriticalSection(&m_Lock);
};

Lock::~Lock() {
    DeleteCriticalSection(&m_Lock);
};

VOID Lock::Lock() {
    EnterCriticalSection(&m_Lock);
};

VOID Lock::Unlock() {
    LeaveCriticalSection(&m_Lock);
};
#elif defined(__LINUX__)
Lock::Lock() {
    pthread_mutex_init(&m_Mutex, NULL);
};

Lock::~Lock() {
    pthread_mutex_destroy(&m_Mutex);
};

VOID Lock::OnLock() {
    pthread_mutex_lock(&m_Mutex);
};

VOID Lock::Unlock() {
    pthread_mutex_unlock(&m_Mutex);
};
#endif


//自动加锁解锁器
AutoLock_T::AutoLock_T(Lock& rLock) {
    m_pLock = &rLock;
    m_pLock->Lock();
}

AutoLock_T::~AutoLock_T() {
    m_pLock->Unlock();
}

AutoLock_T::AutoLock_T() {

}
