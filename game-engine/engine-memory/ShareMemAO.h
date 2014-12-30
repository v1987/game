/* 
 * File:   ShareMemAO.h
 * Author: Vicky.H
 * Email:  eclipser@163.com
 *
 * Created on 2014年12月30日, 下午6:31
 */

#ifndef CN_VICKY__SHAREMEMAO_H
#define	CN_VICKY__SHAREMEMAO_H


#include "../engine-common/Type.h"

#define SHMEM_LOG_PATH	"./Log/ShareMemory.log"

// 共享内存模式

enum CMD_MODE {
    CMD_MODE_CLEARALL = 1, //清除模式
    CMD_MODE_LOADDUMP = 2, //载入dump模式
};


// 共享内存的头信息

struct SMHead {
    SM_KEY m_Key;
    unsigned long m_Size;
    UINT m_HeadVer; //最后存盘版本

    SMHead() {
        m_Key = 0;
        m_Size = 0;
        m_HeadVer = 0;
    }
};

/*
 * 共享内存访问对象
 * ShareMemory	Access	Object
 */
class ShareMemAO {
public:

    ShareMemAO() {
        m_pDataPtr = 0;
        m_hold = 0;
        m_Size = 0;
        m_pHeader = 0;
    }

    ~ShareMemAO() {
    };

    /*
     *	创建ShareMem 访问对象(新创建)
     *
     *  SM_KEY	key		访问键值
     *
     *	uint	Size            访问数据区字节个数
     *
     */
    BOOL Create(SM_KEY key, uint Size);
    /*
     *	销毁对象
     */
    VOID Destory();

    /*
     *	附着ShareMem 访问对象(不是新创建)
     *	SM_KEY	key		访问键值
     *	uint		Size	访问数据区字节个数
     */
    BOOL Attach(SM_KEY, uint Size);
    /*
     *	取消附着(不销毁)
     */
    BOOL Detach();

    /*
     *	 获得数据区指针
     */
    CHAR* GetDataPtr() {
        return m_pDataPtr;
    }

    /*
     *	获得 大小为tSize 的第tIndex 个smu的数据
     */
    CHAR* GetTypePtr(uint tSize, uint tIndex) {
        Assert(tSize > 0);
        Assert(tSize * tIndex < m_Size);
        if (tSize <= 0 || tIndex >= m_Size)
            return NULL;
        return m_pDataPtr + tSize*tIndex;
    }

    /*
     *	获得数据区总大小
     */
    uint GetSize() {
        return m_Size;
    }

    BOOL DumpToFile(CHAR* FilePath);
    BOOL MergeFromFile(CHAR* FilePath);

    UINT GetHeadVer();
    VOID SetHeadVer(UINT ver);

    //命令
    INT m_CmdArg;
private:

    //ShareMemory	内存大小
    uint m_Size;
    // ShareMemory  数据指针
    CHAR* m_pDataPtr;
    // ShareMemory	内存头指针
    CHAR* m_pHeader;
    // ShareMemory	句柄	
    SMHandle m_hold;

};

#endif	/* CN_VICKY__SHAREMEMAO_H */

