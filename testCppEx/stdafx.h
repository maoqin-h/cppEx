// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

#include <windows.h>

// TODO:  在此处引用程序需要的其他头文件
#define ENABLE_TOOLLOG
#include "../cppEx/cppEx.h"


#ifdef _DEBUG
#pragma comment(lib, "../Debug/cppEx_d.lib")
#else
#pragma comment(lib, "../Release/cppEx.lib")
#endif 
