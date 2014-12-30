/* 
 * File:   BaseType.h
 * Author: Vicky.H
 * Email:  eclipser@163.com
 *
 * Created on 2014年12月29日, 下午1:02
 */
#ifndef CN_VICKY__BASETYPE_H
#define	CN_VICKY__BASETYPE_H

/////////////////////////////////////////////////////////////////////////////////
//网络信息预定义宏
/////////////////////////////////////////////////////////////////////////////////
#ifndef FD_SETSIZE
#define FD_SETSIZE      1024
#endif /* FD_SETSIZE */


/////////////////////////////////////////////////////////////////////////////////
//当前包含的系统头文件引用
/////////////////////////////////////////////////////////////////////////////////

#if defined(__WINDOWS__)
#pragma warning ( disable : 4786 )
#include <Windows.h>
#include "crtdbg.h"
#elif defined(__LINUX__)
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <execinfo.h>
#include <exception>
#include <setjmp.h>
#include <sys/types.h>
#include <sys/epoll.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdarg.h>

using namespace std;

///////////////////////////////////////////////////////////////////////
//标准数据类型定义
///////////////////////////////////////////////////////////////////////
#define VOID            void			//标准空
typedef unsigned char	UCHAR;			//标准无符号CHAR
typedef char		CHAR;			//标准CHAR
typedef unsigned int	UINT;			//标准无符号INT
typedef int		INT;			//标准INT
typedef unsigned short	USHORT;			//标准无符号short
typedef short		SHORT;			//标准short
typedef unsigned long	ULONG;			//标准无符号LONG(不推荐使用)
typedef long		LONG;			//标准LONG(不推荐使用)
typedef float		FLOAT;			//标准float

typedef UCHAR		uchar;
typedef USHORT		ushort;
typedef UINT		uint;
typedef ULONG		ulong;
typedef ULONG		IP_t;
typedef USHORT		PacketID_t;
typedef INT		BOOL;
typedef UCHAR		BYTE;


///////////////////////////////////////////////////////////////////////
//基本数据宏定义
///////////////////////////////////////////////////////////////////////

//IP地址的字符最大长度
#define IP_SIZE                         24
#define KEY_SIZE			64
#define MAX_WORLDCOUNT			256
#define TIMELENTH			23
#define OVER_MAX_SERVER                 256

#define INVALID_HANDLE                  -1              //无效的句柄
#define INVALID_ID                      -1              //无效的ID值
#define TRUE                            1               //真
#define FALSE                           0               //假
#define _MAX_PATH                       260             //文件路径的字符最大长度


///////////////////////////////////////////////////////////////////////
//调试预定义宏定义
///////////////////////////////////////////////////////////////////////
#if defined(NDEBUG)
	#define __ENTER_FUNCTION_FOXNET if(1){
	#define __LEAVE_FUNCTION_FOXNET }
#else
	#define __ENTER_FUNCTION_FOXNET if(1){
	#define __LEAVE_FUNCTION_FOXNET }
#endif


#if defined(NDEBUG)
	#define _MY_TRY try
	#define _MY_CATCH catch(...)
#else
	#define _MY_TRY try
	#define _MY_CATCH catch(...)
#endif


//根据指针值删除内存
#ifndef SAFE_DELETE
#define SAFE_DELETE(x)	if( (x)!=NULL ) { delete (x); (x)=NULL; }
#endif
//根据指针值删除数组类型内存
#ifndef SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(x)	if( (x)!=NULL ) { delete[] (x); (x)=NULL; }
#endif
//根据指针调用free接口
#ifndef SAFE_FREE
#define SAFE_FREE(x)	if( (x)!=NULL ) { free(x); (x)=NULL; }
#endif
//根据指针调用Release接口
#ifndef SAFE_RELEASE
#define SAFE_RELEASE(x)	if( (x)!=NULL ) { (x)->Release(); (x)=NULL; }
#endif


#endif	/* CN_VICKY__BASETYPE_H */

