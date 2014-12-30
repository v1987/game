/* 
 * File:   GameUtil.h
 * Author: Vicky.H
 * Email:  eclipser@163.com
 *
 * Created on 2014年12月30日, 上午11:20
 */

#ifndef CN_VICKY__GAMEUTIL_H
#define	CN_VICKY__GAMEUTIL_H

#include "../engine-common/Type.h"

#define __PI			3.1415f
#define __HALF_PI		__PI / 2
#define __QUARTER_PI            __PI / 4

///////////////////////////////////////////////////////////////////////
//基本功能性函数定义
///////////////////////////////////////////////////////////////////////

//当前线程挂起一定时间
extern VOID MySleep(UINT millionseconds = 0);

extern TID MyGetCurrentThreadID();

extern CHAR* MySocketError();

#endif	/* CN_VICKY__GAMEUTIL_H */

