/* 
 * File:   SMUManager.h
 * Author: Vicky.H
 * Email:  eclipser@163.com
 *
 * Created on 2014年12月30日, 下午6:40
 */

#ifndef CN_VICKY__SMUMANAGER_H
#define	CN_VICKY__SMUMANAGER_H

#include "../engine-common/Type.h"

#define MAX_MANAGER_SMU		5000
#define MAX_SM_OBJ_NUM		10

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

