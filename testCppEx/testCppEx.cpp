// testCppEx.cpp : �������̨Ӧ�ó������ڵ㡣
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

