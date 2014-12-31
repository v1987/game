/* 
 * File:   SMULogicManager.h
 * Author: Vicky.H
 * Email:  eclipser@163.com
 *
 * Created on 2014年12月31日, 上午10:04
 */

#ifndef CN_VICKY__SMULOGICMANAGER_H
#define	CN_VICKY__SMULOGICMANAGER_H


#include "SMUPool.h"
#include "SMUManager.h"
#include "CommandThread.h"


#define MAX_SERVER_IDLE_TIME	30*1000  //服务器停止响应时间(毫秒)

extern GLOBAL_CONFIG g_SMConfig;

template<typename T>
class SMULogicManager {
public:

    SMULogicManager();

    ~SMULogicManager();

public:

    BOOL Init(SMUPool<T>* pPool);
    BOOL HeartBeat();
    
    
    BOOL DoSaveAll();
    BOOL DoNormalSave();
    BOOL DoClear();
    BOOL DoPostInit();
private:

    SMUPool<T>* m_PoolSharePtr;
    T* m_pSMU;
    UINT m_FinalSaveTime;
    BOOL m_bReady;
    UINT m_OldVer;
    UINT m_OldCheckTime;

};

#endif	/* CN_VICKY__SMULOGICMANAGER_H */

