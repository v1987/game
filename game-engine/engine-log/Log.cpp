#include "Log.h"
#include "../engine-utils/GameUtil.h"
#include "../engine-utils/TimeManager.h"

// 线程锁
Lock g_log_lock;

Log* g_pLog = NULL;

Log::Log() {
    __ENTER_FUNCTION

    for (INT i = 0; i < LOG_FILE_NUMBER; i++) {
        m_LogCache[i] = NULL;
        m_LogPos[i] = 0;
    }
    m_CacheSize = 0;
    m_DayTime = 0;

    __LEAVE_FUNCTION
}

Log::~Log() {
    __ENTER_FUNCTION

    for (INT i = 0; i < LOG_FILE_NUMBER; i++) {
        SAFE_DELETE_ARRAY(m_LogCache[i]);
    }
    m_CacheSize = 0;

    __LEAVE_FUNCTION
}

BOOL Log::Init() {
    __ENTER_FUNCTION

    m_CacheSize = DEFAULT_LOG_CACHE_SIZE;
    //最小化内存占用
    //______________________
    for (INT i = 0; i < LOG_FILE_NUMBER; i++) {
        m_LogCache[i] = new CHAR[m_CacheSize];
        if (m_LogCache[i] == NULL) {
            return FALSE;
        }
        m_LogPos[i] = 0;
    }

    //______________________
    if (g_pTimeManager)
        m_DayTime = g_pTimeManager->GetDayTime();
    else
        m_DayTime = 6000;

    return TRUE;

    __LEAVE_FUNCTION

    return FALSE;
}

VOID Log::FastSaveLog(INT logid, CHAR* msg, ...) {
    __ENTER_FUNCTION

    if (logid < 0 || logid >= LOG_FILE_NUMBER)
        return;

    CHAR buffer[2048];
    va_list argptr;

    try {
        va_start(argptr, msg);
        vsprintf(buffer, msg, argptr);
        va_end(argptr);

        if (g_pTimeManager) {
            CHAR szTime[64];
            sprintf(szTime, " (%d)(T=%.4f)\r\n",
                    MyGetCurrentThreadID(),
                    (FLOAT) (g_pTimeManager->RunTime()) / 1000.0);
            strcat(buffer, szTime);
        }
    } catch (...) {
        Assert(FALSE);
        return;
    }

    INT iLen = (INT) strlen(buffer);
    if (iLen <= 0)
        return;

    //最小化内存占用
    //______________________
    CHAR szName[_MAX_PATH];
    GetLogName(logid, szName);

    SaveLog(szName, buffer);
    return;
    //______________________

    m_LogLock[logid].OnLock();
    try {
        memcpy(m_LogCache[logid] + m_LogPos[logid], buffer, iLen);
        m_LogPos[logid] += iLen;
        printf(buffer);
    } catch (...) {
    }
    m_LogLock[logid].Unlock();



    if (m_LogPos[logid] > (DEFAULT_LOG_CACHE_SIZE * 2) / 3) {
        FlushLog(logid);
    }
    return;

    __LEAVE_FUNCTION

    return;
}

VOID Log::FlushLog(INT logid) {
    __ENTER_FUNCTION

    CHAR szName[_MAX_PATH];
    GetLogName(logid, szName);

    m_LogLock[logid].OnLock();
    try {
        FILE* f = fopen(szName, "ab");
        fwrite(m_LogCache[logid], 1, m_LogPos[logid], f);
        fclose(f);
        m_LogPos[logid] = 0;
    } catch (...) {
    }
    m_LogLock[logid].Unlock();
    return;

    __LEAVE_FUNCTION
}

VOID Log::FlushLog_All() {
    __ENTER_FUNCTION

    for (INT i = 0; i < LOG_FILE_NUMBER; i++) {
        FlushLog(i);
    }

    __LEAVE_FUNCTION
}

VOID Log::GetLogName(INT logid, CHAR* szName) {
    __ENTER_FUNCTION

    sprintf(szName, "%s_%d.log", g_pLogFileName[logid], m_DayTime);

    __LEAVE_FUNCTION
}

VOID Log::SaveLog(CHAR* filename, CHAR* msg, ...) {
    __ENTER_FUNCTION

    g_log_lock.OnLock();

    CHAR buffer[2048];
    memset(buffer, 0, 2048);

    va_list argptr;

    _MY_TRY{
        va_start(argptr, msg);
        vsprintf(buffer, msg, argptr);
        va_end(argptr);

        CHAR szTime[64];
        if (g_pTimeManager) {
            memset(szTime, 0, 64);
            sprintf(szTime, " (%d)(T=%.4f)\r\n",
                    MyGetCurrentThreadID(),
                    (FLOAT) (g_pTimeManager->RunTime()) / 1000.0);
            strcat(buffer, szTime);
        }
        FILE* f = fopen(filename, "ab");
        fwrite(buffer, 1, strlen(buffer), f);
        fclose(f);

        printf(buffer);
    }
    _MY_CATCH{
        printf("a big error here");
    }

    g_log_lock.Unlock();
    return;

    __LEAVE_FUNCTION

    g_log_lock.Unlock();
    return;
}

VOID Log::RemoveLog(CHAR* filename) {
    __ENTER_FUNCTION

    g_log_lock.OnLock();

    FILE* f = fopen(filename, "w");
    fclose(f);

    g_log_lock.Unlock();
    return;

    __LEAVE_FUNCTION

    g_log_lock.Unlock();
    return;
}
