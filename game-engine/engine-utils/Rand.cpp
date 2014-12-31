#include "Rand.h"

UINT Rand::m_uKey = 0;
CHAR Rand::m_pKey[MAX_KEY_SIZE];
Lock Rand::m_Lock;
RandGen g_RandGen = RandGen((unsigned) time(NULL));

Rand::Rand() {
}

Rand::~Rand() {
}

VOID Rand::SetRand(UINT uKey) {
    m_Lock.OnLock();

    m_uKey = uKey % MAX_KEY_SIZE;

    m_Lock.Unlock();
}

UINT Rand::GetRand() {
    m_Lock.OnLock();

    if (m_uKey == 0) {
        srand((unsigned) time(NULL));
        for (INT i = 0; i < MAX_KEY_SIZE; i++) {
            m_pKey[i] = rand() % 255;
        }
    }

    m_uKey++;
    if (m_uKey >= MAX_KEY_SIZE - sizeof (UINT))
        m_uKey = 1;

    UINT nRet = *((UINT*) (m_pKey + m_uKey));

    m_Lock.Unlock();

    return nRet;
}

UINT RandGen::GetRand(INT nStart, INT nEnd) {
    return (INT) ((nEnd - nStart) * g_RandGen.RandDouble()) + nStart;
}

