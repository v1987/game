/* 
 * File:   SMUManager.h
 * Author: Vicky.H
 * Email:  eclipser@163.com
 *
 * Created on 2014年12月30日, 下午6:40
 */

#ifndef CN_VICKY__SMUMANAGER_H
#define	CN_VICKY__SMUMANAGER_H

#include "ShareMemAO.h"

#define MAX_MANAGER_SMU		5000
#define MAX_SM_OBJ_NUM		10

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

template<typename T>
class SMUManager {
    // smu 数据
    T *m_pSMU[MAX_MANAGER_SMU];
    // smu 个数
    INT m_nCount;

public:

    SMUManager();

    ~SMUManager();

    //初始化操作

    VOID Init();

    BOOL HeartBeat(UINT uTime = 0);

    /*
     *	添加一个SMUPool 创建的数据到管理器
     */

    BOOL AddSMU(T* pSMU);

    /*
     *	删除一个SMUPool 创建的数据到管理器
     */
    BOOL DelSMU(T* pSMU);

    /*
     *	根据SMUId 检索SMU
     */
    T* GetSMU(SMUID_t SMUId);

};

#endif	/* CN_VICKY__SMUMANAGER_H */

