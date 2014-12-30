/* 
 * File:   Type.h
 * Author: Vicky.H
 * Email:  eclipser@163.com
 *
 * Created on 2014年12月29日, 下午1:01
 */

#ifndef CN_VICKY__TYPE_H
#define	CN_VICKY__TYPE_H


//
//文件名称：	Type.h
//功能描述：	类型定义，区分不同操作系统间系统调用的设置，所有当前工程
//				内的代码都必须第一个引用此文件
//版本说明：	Windows操作系统需要定义宏：__WINDOWS__
//				Linux操作系统需要定义宏：__LINUX__
//
//
//当前位置可以定义操作系统使用情况，或者也可以在工程文件内预定义
//#ifndef __WINDOWS__
//	#define __WINDOWS__
//#endif
#ifndef __LINUX__
#define __LINUX__
#endif

#include "BaseType.h"
#include "Assertx.h"
#include <vector>

typedef SHORT ID_t;
typedef USHORT SMUID_t;
typedef ULONG SM_KEY;
typedef UINT ObjID_t; //场景中固定的所有OBJ拥有不同的ObjID_t

typedef INT Time_t; //时间类型

typedef struct _Int64 {
    LONG a;
    ULONG b;
} Int64;

#if defined(__LINUX__) || defined(__WIN_CONSOLE__)
	typedef UCHAR  BYTE;
	typedef USHORT WORD;
	typedef	ULONG  DWORD;
#endif

#if defined(__WINDOWS__)
	typedef DWORD		TID ;
	//用来定义玩家各个子模型是否可见 ###
	typedef unsigned __int64 MODEL_PART;
#elif defined(__LINUX__)
	typedef pthread_t           TID ;
	typedef unsigned long long  MODEL_PART;
	typedef const char*         LPCSTR;
#endif

#if defined(__LINUX__)
	typedef		INT		SMHandle;
#elif defined(__WINDOWS__)
	typedef		VOID*           SMHandle;
#endif

typedef		VOID*	DBHandle;
        
#if defined(__WINDOWS__)
	#if defined(NDEBUG)
		#define __ENTER_FUNCTION {try{
		#define __LEAVE_FUNCTION }catch(...){AssertSpecial(FALSE,__FUNCTION__);}}
	#else
		#define __ENTER_FUNCTION {try{
		#define __LEAVE_FUNCTION }catch(...){AssertSpecial(FALSE,__FUNCTION__);}}
	#endif
#else	//linux
	#define __ENTER_FUNCTION {try{
	#define __LEAVE_FUNCTION }catch(...){AssertSpecial(FALSE,__PRETTY_FUNCTION__);}}
#endif 
        
#endif	/* CN_VICKY__TYPE_H */

