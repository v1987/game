/* 
 * File:   Log.h
 * Author: Vicky.H
 * Email:  eclipser@163.com
 *
 * Created on 2014年12月30日, 下午3:17
 */

#ifndef CN_VICKY__LOG_H
#define	CN_VICKY__LOG_H

#include "../engine-file/File.h"
#include "../engine-thread/Lock.h"

enum LOG_FILE_NAME_ID {
    LOG_FILE_0 = 0,
    LOG_FILE_1 = 1,
    LOG_FILE_2 = 2,
    LOG_FILE_3 = 3,

    LOG_FILE_NUMBER,
};


// 具体日志坐标对应的名称
const CHAR* g_pLogFileName[] =
{
    "./Log/login",          //0		LOG_FILE_0
    "./Log/debug",          //1		LOG_FILE_1
    "./Log/error",          //2		LOG_FILE_2
    "./Log/functions",      //3		LOG_FILE_3
    "\0"
};


#define DEFAULT_LOG_CACHE_SIZE 1024 * 1024 * 4

class Log {
public:
    Log();
    ~Log();

    BOOL Init();

    //向日志缓存写入日志信息
    VOID FastSaveLog(INT logid, const CHAR* msg, ...);

    //将日志内存数据写入文件
    VOID FlushLog(INT logid);

    //取得日志有效数据大小

    INT GetLogSize(INT logid) {
        return m_LogPos[logid];
    }

    //取得保存日志的文件名称
    VOID GetLogName(INT logid, CHAR* szName);

    //刷新每个日志文件
    VOID FlushLog_All();

    //取得日期天数

    UINT GetDayTime() {
        return m_DayTime;
    }
    //设置日期天数

    VOID SetDayTime(UINT daytime) {
        m_DayTime = daytime;
    }


    //支持异步写入操作的日志写入
    static VOID SaveLog(const CHAR* filename, const CHAR* msg, ...);
    //删除日志内容
    static VOID RemoveLog(const CHAR* filename);


private:
    CHAR*   m_LogCache  [LOG_FILE_NUMBER]; //日志内存区
    INT     m_LogPos    [LOG_FILE_NUMBER]; //日志当前有效数据位置
    Lock    m_LogLock   [LOG_FILE_NUMBER]; //日志读写锁
    
    INT     m_CacheSize;
    UINT    m_DayTime;
};

#ifdef __LINUX__
#define SaveCodeLog()	(Log::SaveLog( SERVER_ERRORFILE, "%s %d %s", __FILE__,__LINE__,__PRETTY_FUNCTION__ ))
#else
#define SaveCodeLog()	(Log::SaveLog( SERVER_ERRORFILE, "%s %d %s", __FILE__,__LINE__,__FUNCTION__ ))
#endif

extern Log* g_pLog;

#endif	/* CN_VICKY__LOG_H */

