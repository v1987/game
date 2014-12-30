#include "Lock.h"

//共享锁
#if defined(__WINDOWS__)

MyLock::MyLock() {
    InitializeCriticalSection(&m_Lock);
};

MyLock::~MyLock() {
    DeleteCriticalSection(&m_Lock);
};

VOID MyLock::Lock() {
    EnterCriticalSection(&m_Lock);
};

VOID MyLock::Unlock() {
    LeaveCriticalSection(&m_Lock);
};
#elif defined(__LINUX__)
MyLock::MyLock() {
    pthread_mutex_init(&m_Mutex, NULL);
};

MyLock::~MyLock() {
    pthread_mutex_destroy(&m_Mutex);
};

VOID MyLock::Lock() {
    pthread_mutex_lock(&m_Mutex);
};

VOID MyLock::Unlock() {
    pthread_mutex_unlock(&m_Mutex);
};
#endif


//自动加锁解锁器
AutoLock_T::AutoLock_T(MyLock& rLock) {
    m_pLock = &rLock;
    m_pLock->Lock();
}

AutoLock_T::~AutoLock_T() {
    m_pLock->Unlock();
}

AutoLock_T::AutoLock_T() {

}
