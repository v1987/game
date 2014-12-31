/* 
 * File:   CommandThread.h
 * Author: Vicky.H
 * Email:  eclipser@163.com
 *
 * Created on 2014年12月31日, 上午10:06
 */

#ifndef CN_VICKY__COMMANDTHREAD_H
#define	CN_VICKY__COMMANDTHREAD_H


#include "../engine-thread/Thread.h"

enum SM_COMMANDS {
    CMD_UNKNOW,
    CMD_SAVE_ALL, // 存储共享内存区的数据
    CMD_CLEAR_ALL, // 清理共享内存区的数据
};

struct SM_COMMANDS_STATE {
    SM_COMMANDS cmdType;

    union {
        INT iParam[6];
        FLOAT fParam[6];
        CHAR cParam[24];
    };
};

// 配置
struct GLOBAL_CONFIG {

    GLOBAL_CONFIG() {
        Commands.cmdType = CMD_UNKNOW;
    }
    SM_COMMANDS_STATE Commands;
};


extern GLOBAL_CONFIG	g_SMConfig;


//用来处理命令行数据

class CommandThread : public Thread {
public:

    CommandThread() {
        m_Active = TRUE;
    }

    ~CommandThread() {
    };

    //主循环
    virtual VOID run();

    //停止线程执行

    virtual VOID stop() {
        m_Active = FALSE;
    };

    //判断当前线程是否激活

    BOOL IsActive() {
        return m_Active;
    };

private:
    BOOL m_Active;

};

extern CommandThread g_CommandThread;


// 解析命令行命令: saveall/clearall

class CmdParser {
public:
    static BOOL HandleInput();

private:
    static SM_COMMANDS_STATE ParserCommandType(CHAR* pBuff);
};


#endif	/* CN_VICKY__COMMANDTHREAD_H */

