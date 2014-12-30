/* 
 * File:   Timer.h
 * Author: Vicky.H
 * Email:  eclipser@163.com
 *
 * Created on 2014年12月30日, 下午2:18
 */

#ifndef CN_VICKY__TIMER_H
#define	CN_VICKY__TIMER_H

#include "../engine-common/Type.h"

class Timer {
private:
    UINT m_uTickTerm;
    UINT m_uTickOld;

public:
    BOOL m_bOper;

public:

    Timer();

    BOOL IsSetTimer();

    VOID SetTermTime(UINT uTerm);

    UINT GetTermTime();

    UINT GetTickOldTime();

    VOID CleanUp();

    VOID BeginTimer(UINT uTerm, UINT uNow);

    BOOL CountingTimer(UINT uNow);

    UINT GetLeaveTime(UINT uNow);
};


#endif	/* CN_VICKY__TIMER_H */

