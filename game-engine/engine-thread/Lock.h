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

class MyLock {
    CRITICAL_SECTION m_Lock;
public:

    MyLock();

    ~MyLock();

    VOID Lock();

    VOID Unlock();
};
#elif defined(__LINUX__)

class MyLock {
    pthread_mutex_t m_Mutex;
public:

    MyLock();

    ~MyLock();

    VOID Lock();

    VOID Unlock();
};
#endif
//自动加锁解锁器

class AutoLock_T {
public:

    AutoLock_T(MyLock& rLock);
    ~AutoLock_T();
private:
    AutoLock_T();
    MyLock* m_pLock;
};

#endif	/* CN_VICKY__LOCK_H */

