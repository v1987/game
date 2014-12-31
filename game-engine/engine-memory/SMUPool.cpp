#include "SMUPool.h"
#include "../engine-log/Log.h"


template<typename T>
SMUPool<T>::SMUPool() {
    __ENTER_FUNCTION
    m_pRefObjPtr = NULL;
    m_hObj = NULL;
    m_nMaxSize = -1;
    m_nPosition = -1;
    __LEAVE_FUNCTION
}

template<typename T>
SMUPool<T>::~SMUPool() {
    __ENTER_FUNCTION

    SAFE_DELETE(m_pRefObjPtr);
    SAFE_DELETE_ARRAY(m_hObj);

    __LEAVE_FUNCTION
}

template<typename T>
BOOL SMUPool<T>::Init(uint nMaxCount, SM_KEY key, SMPOOL_TYPE SMPT) {
    __ENTER_FUNCTION


    m_pRefObjPtr = new ShareMemAO();

    Assert(m_pRefObjPtr);

    if (!m_pRefObjPtr)
        return FALSE;

    m_pRefObjPtr->m_CmdArg = g_CmdArgv;

    BOOL ret;

    ret = m_pRefObjPtr->Attach(key, sizeof (T) * nMaxCount + sizeof (SMHead));

    if (SMPT == SMPT_SHAREMEM) {
        if (!ret) {
            ret = m_pRefObjPtr->Create(key, sizeof (T) * nMaxCount + sizeof (SMHead));

        }
    } else {
        if (!ret) {
            return FALSE;
        }
    }

    if (!ret) {
        if (m_pRefObjPtr->m_CmdArg == CMD_MODE_CLEARALL) {
            return TRUE;
        }

        Log::SaveLog(SHMEM_LOG_PATH, "Setup SMU block fail!");
        Assert(ret);
        return ret;

    }

    m_nMaxSize = nMaxCount;
    m_nPosition = 0;
    m_hObj = new T* [m_nMaxSize];

    INT i;
    for (i = 0; i < m_nMaxSize; i++) {
        m_hObj[i] = reinterpret_cast<T*> (m_pRefObjPtr->GetTypePtr(sizeof (T), i));
        if (m_hObj[i] == NULL) {
            Assert(m_hObj[i] != NULL);
            return FALSE;
        }
    }

    m_key = key;

    return TRUE;
    __LEAVE_FUNCTION
    return FALSE;
}

template<typename T>
BOOL SMUPool<T>::Finalize() {
    __ENTER_FUNCTION

    Assert(m_pRefObjPtr);
    m_pRefObjPtr->Destory();
    return TRUE;

    __LEAVE_FUNCTION

    return FALSE;

}

template<typename T>
T* SMUPool<T>::NewObj(VOID) {
    __ENTER_FUNCTION

    Assert(m_nPosition < m_nMaxSize);
    if (m_nPosition >= m_nMaxSize) {
        return NULL;
    }

    T *pObj = m_hObj[m_nPosition];
    pObj->SetPoolID((UINT) m_nPosition);
    m_nPosition++;
    return pObj;
    __LEAVE_FUNCTION
    return NULL;
}

template<typename T>
VOID SMUPool<T>::DeleteObj(T *pObj) {
    __ENTER_FUNCTION

    Assert(pObj != NULL);
    if (pObj == NULL) {
        return;
    }
    Assert(m_nPosition > 0);
    if (m_nPosition <= 0) {
        return;
    }
    UINT uDelIndex = pObj->GetPoolID();
    Assert(uDelIndex < (UINT) m_nPosition);
    if (uDelIndex >= (UINT) m_nPosition) {
        return;
    }
    m_nPosition--;
    T *pDelObj = m_hObj[uDelIndex];
    m_hObj[uDelIndex] = m_hObj[m_nPosition];
    m_hObj[m_nPosition] = pDelObj;

    m_hObj[uDelIndex]->SetPoolID(uDelIndex);
    m_hObj[m_nPosition]->SetPoolID(INVALID_ID);
    __LEAVE_FUNCTION
}

template<typename T>
T* SMUPool<T>::GetPoolObj(INT iIndex) {
    Assert(iIndex < m_nMaxSize);
    return m_hObj[iIndex];
}

template<typename T>
INT SMUPool<T>::GetPoolMaxSize() {
    return m_nMaxSize;
}

template<typename T>
INT SMUPool<T>::GetPoolSize() {
    return m_nPosition;
}

template<typename T>
SM_KEY SMUPool<T>::GetKey() {
    return m_key;
}

template<typename T>
BOOL SMUPool<T>::DumpToFile(CHAR* FilePath) {
    if (!m_pRefObjPtr) {
        Assert(m_pRefObjPtr);
        return FALSE;
    }

    return m_pRefObjPtr->DumpToFile(FilePath);
}

template<typename T>
BOOL SMUPool<T>::MergeFromFile(CHAR* FilePath) {
    if (!m_pRefObjPtr) {
        Assert(m_pRefObjPtr);
        return FALSE;
    }
    return m_pRefObjPtr->MergeFromFile(FilePath);
}

template<typename T>
UINT SMUPool<T>::GetHeadVer() {
    Assert(m_pRefObjPtr);
    return m_pRefObjPtr->GetHeadVer();
}

template<typename T>
VOID SMUPool<T>::SetHeadVer(UINT ver) {
    Assert(m_pRefObjPtr);
    return m_pRefObjPtr->SetHeadVer(ver);
}

