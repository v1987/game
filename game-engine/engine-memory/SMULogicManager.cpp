#include "SMULogicManager.h"
#include "../engine-log/Log.h"
#include "../engine-utils/TimeManager.h"

template<typename T>
SMULogicManager<T>::SMULogicManager() : m_PoolSharePtr(0), m_pSMU(0), m_FinalSaveTime(0) {
}

template<typename T>
SMULogicManager<T>::~SMULogicManager() {
}

template<typename T>
BOOL SMULogicManager<T>::Init(SMUPool<T>* pPool) {
    if (!pPool) return FALSE;
    m_PoolSharePtr = pPool;
    m_PoolSharePtr->SetHeadVer(0);
    m_OldCheckTime = g_pTimeManager->RunTime();
    m_OldVer = 0;
    return DoPostInit();
}

template<typename T>
BOOL SMULogicManager<T>::HeartBeat() {

    UINT uTime = g_pTimeManager->RunTime();

    if ((uTime - m_OldCheckTime) > MAX_SERVER_IDLE_TIME) {
        m_OldCheckTime = uTime;
        UINT ver = m_PoolSharePtr->GetHeadVer();
        if ((ver == m_OldVer) && m_OldVer > 0) {
            m_OldVer = 0;

            Log::SaveLog("./Log/ShareMemory.log", "Receive Server Crash command..");
            BOOL bRet = DoSaveAll();

            //清理对应的数据标志

            DoClear();

            m_PoolSharePtr->SetHeadVer(0);
            return bRet;
        }
        m_OldVer = ver;
    }

    switch (g_SMConfig.Commands.cmdType) {
        case CMD_SAVE_ALL:
        {
            return DoSaveAll();
            break;
        }
        case CMD_CLEAR_ALL:
        {
            return DoClear();
            break;
        }
        case CMD_UNKNOW:
        {
            return DoNormalSave();
            break;
        }
        default:
        {
            return FALSE;
        }
    }

}



//==============================================================================
// 泛型实现:

//HumanSMU 的心跳
//
//template<>
//BOOL SMULogicManager<HumanSMU>::DoSaveAll() {
//}
//
//template<>
//BOOL SMULogicManager<HumanSMU>::DoNormalSave() {
//
//}
//
//template<>
//BOOL SMULogicManager<HumanSMU>::DoClear() {
//
//}
//
//template<>
//BOOL SMULogicManager<HumanSMU>::DoPostInit() {
//}


