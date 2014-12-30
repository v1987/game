#include "Timer.h"

Timer::Timer() {
    CleanUp();
}

BOOL Timer::IsSetTimer() {
    return m_bOper;
}

VOID Timer::SetTermTime(UINT uTerm) {
    m_uTickTerm = uTerm;
}

UINT Timer::GetTermTime() {
    return m_uTickTerm;
}

UINT Timer::GetTickOldTime() {
    return m_uTickOld;
}

VOID Timer::CleanUp() {
    m_uTickTerm = 0;
    m_bOper = FALSE;
    m_uTickOld = 0;
}

VOID Timer::BeginTimer(UINT uTerm, UINT uNow) {
    m_bOper = TRUE;
    m_uTickTerm = uTerm;
    m_uTickOld = uNow;
}

BOOL Timer::CountingTimer(UINT uNow) {
    if (!m_bOper)
        return FALSE;

    UINT uNew = uNow;

    if (uNew < m_uTickOld + m_uTickTerm)
        return FALSE;

    m_uTickOld = uNew;

    return TRUE;
}

UINT Timer::GetLeaveTime(UINT uNow)//剩余时间;
{
    if (!CountingTimer(uNow)) {
        return m_uTickTerm + m_uTickOld - uNow;
    }
    return 0;
}

