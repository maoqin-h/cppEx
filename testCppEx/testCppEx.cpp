// testCppEx.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

NP_CPPEX::CMyToolLog g_myLog;

int main()
{
	g_myLog.CreateConsoleLog();

	//LOG(INFO) << ""

	g_myLog.DestroyConsoleLog();
    return 0;
}

