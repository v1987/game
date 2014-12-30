/* 
 * File:   Thread.h
 * Author: Vicky.H
 * Email:  eclipser@163.com
 *
 * Created on 2014年12月29日, 下午12:52
 */

#ifndef CN_VICKY__THREAD_H
#define	CN_VICKY__THREAD_H

#include "../engine-common/Type.h"

class Thread {
public:

    enum ThreadStatus {
        READY, // 当前线程处于准备状态
        RUNNING, // 处于运行状态
        EXITING, // 线程正在退出
        EXIT // 已经退出
    };

public:

    // constructor
    Thread();

    // destructor
    virtual ~Thread();


public:

    VOID start();

    virtual VOID stop();

    VOID exit(VOID * retval = NULL);

    virtual VOID run();


public:
    // get thread identifier

    TID getTID() {
        return m_TID;
    }

    // get/set thread's status

    ThreadStatus getStatus() {
        return m_Status;
    }

    VOID setStatus(ThreadStatus status) {
        m_Status = status;
    }

private:
    // thread identifier variable
    TID m_TID;

    // thread status
    ThreadStatus m_Status;

#if defined(__WINDOWS__)
    HANDLE m_hThread;
#endif


};

extern uint g_QuitThreadCount;

#if defined(__LINUX__)
VOID * MyThreadProcess(VOID * derivedThread);
#elif defined(__WINDOWS__)
DWORD WINAPI MyThreadProcess(VOID* derivedThread);
#endif

#endif	/* CN_VICKY__THREAD_H */

