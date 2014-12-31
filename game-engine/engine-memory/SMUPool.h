/* 
 * File:   SMUPool.h
 * Author: Vicky.H
 * Email:  eclipser@163.com
 *
 * Created on 2014年12月31日, 上午10:00
 */

#ifndef CN_VICKY__SMUPOOL_H
#define	CN_VICKY__SMUPOOL_H

#include "ShareMemAO.h"

extern INT g_CmdArgv;

// 共享内存类型

enum SMPOOL_TYPE {
    SMPT_SHAREMEM,
    SMPT_SERVER,
    SMPT_WORLD
};



//ShareMemory 单元池

template<typename T>
class SMUPool {
public:

    SMUPool();

    ~SMUPool();

    BOOL Init(uint nMaxCount, SM_KEY key, SMPOOL_TYPE SMPT);

    BOOL Finalize();

    T* NewObj(VOID);

    VOID DeleteObj(T *pObj);

    T* GetPoolObj(INT iIndex);

    INT GetPoolMaxSize();

    INT GetPoolSize();

    SM_KEY GetKey();

    BOOL DumpToFile(CHAR* FilePath);

    BOOL MergeFromFile(CHAR* FilePath);

    UINT GetHeadVer();

    VOID SetHeadVer(UINT ver);


private:
    T **m_hObj; //管理对象SMU数组
    INT m_nMaxSize; //最大容量
    INT m_nPosition; //当前使用偏移
    ShareMemAO* m_pRefObjPtr; //引用SMObject
    SM_KEY m_key; //对应的ShareMemory Key

};


#endif	/* CN_VICKY__SMUPOOL_H */

