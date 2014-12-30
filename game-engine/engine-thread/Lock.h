/* 
 * File:   Lock.h
 * Author: Vicky.H
 * Email:  eclipser@163.com
 *
 * Created on 2014年12月30日, 下午1:41
 */

#ifndef CN_VICKY__LOCK_H
#define	CN_VICKY__LOCK_H

#include "../engine-common/Type.h"

//共享锁
#if defined(__WINDOWS__)

class Lock {
    CRITICAL_SECTION m_Lock;
public:

    Lock();

    ~Lock();

    VOID Lock();

    VOID Unlock();
};
#elif defined(__LINUX__)

class Lock {
    pthread_mutex_t m_Mutex;
public:

    Lock();

    ~Lock();

    VOID OnLock();

    VOID Unlock();
};
#endif
//自动加锁解锁器

class AutoLock_T {
public:

    AutoLock_T(Lock& rLock);
    ~AutoLock_T();
private:
    AutoLock_T();
    Lock* m_pLock;
};

#endif	/* CN_VICKY__LOCK_H */

