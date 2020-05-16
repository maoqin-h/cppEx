// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 从 Windows 头中排除极少使用的资料
// Windows 头文件: 
#include <windows.h>



// TODO:  在此处引用程序需要的其他头文件
#include <filesystem>


#define GOOGLE_GLOG_DLL_DECL
#define GLOG_NO_ABBREVIATED_SEVERITIES
#include "glog/logging.h"


#ifdef _DEBUG
#ifdef _MT
#ifdef _DLL
#pragma comment(lib, "glog/lib/glogd.lib")
#else
#pragma comment(lib, "glog/lib/glogMTd.lib")
#endif
#endif
#else
#ifdef _MT
#ifdef _DLL
#pragma comment(lib, "glog/lib/glog.lib")
#else
#pragma comment(lib, "glog/lib/glogMT.lib")
#endif
#endif
#endif


