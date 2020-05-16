// testCppEx.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>

NP_CPPEX::CMyToolLog g_myLog;

int main()
{

	NP_CPPEX::CMyToolLog::LOGINFO("this is loginfo 123456");
	NP_CPPEX::CMyToolLog::LOGINFO("this is loginfo 654321");
	NP_CPPEX::CMyToolLog::LOGWARNING("this is warning 654321");
	NP_CPPEX::CMyToolLog::LOGERROR("this is error 654321");

	OutputDebugString(L"ssss");
	system("pause");
    return 0;
}

