#include "SMUManager.h"


template<typename T>
SMUManager<T>::SMUManager() : m_nCount(0) {
    memset(m_pSMU, 0, sizeof (T*) * MAX_MANAGER_SMU);
}

template<typename T>
SMUManager<T>::~SMUManager() {
}

//初始化操作

template<typename T>
VOID SMUManager<T>::Init() {

    __ENTER_FUNCTION
    m_nCount = 0;
    return TRUE;
    __LEAVE_FUNCTION
    return FALSE;

}

/*
 *	添加一个SMUPool 创建的数据到管理器
 */
template<typename T>
BOOL SMUManager<T>::AddSMU(T* pSMU) {
    __ENTER_FUNCTION

    Assert(m_nCount < MAX_MANAGER_SMU);
    if (m_nCount >= MAX_MANAGER_SMU)
        return FALSE;

    m_pSMU[m_nCount] = pSMU;
    m_pSMU->SetSMUID(m_nCount);
    m_nCount++;
    return TRUE;
    __LEAVE_FUNCTION
    return FALSE;
}

/*
 *	删除一个SMUPool 创建的数据到管理器
 */
template<typename T>
BOOL SMUManager<T>::DelSMU(T* pSMU) {
    __ENTER_FUNCTION

    UINT uID = pSMU->GetSMUID();

    Assert(uID < (UINT) m_nCount);
    if (uID >= (UINT) m_nCount)
        return FALSE;

    Assert(m_pSMU[uID] == pSMU);
    if (m_pSMU[uID] != pSMU)
        return FALSE;

    m_pSMU[uID] = m_pSMU[m_nCount - 1];
    m_pSMU[uID]->SetSMUID(uID); //重新改变索引
    pSMU->SetSMUID(INVALID_ID);
    m_nCount--;

    return TRUE;
    __LEAVE_FUNCTION
    return FALSE;
}

/*
 *	根据SMUId 检索SMU
 */
template<typename T>
T* SMUManager<T>::GetSMU(SMUID_t SMUId) {
    Assert(SMUId < m_nCount);
    if (SMUId >= m_nCount)
        return NULL;
    return m_pSMU[SMUId];
}



// ===============================

// TODO 定义具体的共享内存管理器
// template<typename T>
// BOOL SMUManager<T>::HeartBeat(UINT uTime = 0);


// 如:
// SMUPool<HumanSMU>*	g_pHumanSMUPool = NULL;;
//
// BOOL	SMUManager<HumanSMU>::HeartBeat(UINT uTime/* =0 */) {
// 	return TRUE;
// }