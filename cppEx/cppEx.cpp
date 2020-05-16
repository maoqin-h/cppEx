// cppEx.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "cppEx.h"


//// 这是导出变量的一个示例
//CPPEX_API int ncppEx=0;
//
//// 这是导出函数的一个示例。
//CPPEX_API int fncppEx(void)
//{
//    return 42;
//}
//
//// 这是已导出类的构造函数。
//// 有关类定义的信息，请参阅 cppEx.h
//CcppEx::CcppEx()
//{
//    return;
//}

CPPEX_API wchar_t* NP_CPPEX::AnsiToUnicode(const char* szStr)
{
	int nLen = MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, szStr, -1, NULL, 0);
	if (nLen == 0)
		return NULL;

	wchar_t* pResult = new wchar_t[nLen] {};
	MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, szStr, -1, pResult, nLen);
	return pResult;
}

CPPEX_API char* NP_CPPEX::UnicodeToAnsi(const wchar_t* szStr)
{
	int nLen = WideCharToMultiByte(CP_ACP, 0, szStr, -1, NULL, 0, NULL, NULL);
	if (nLen == 0)
		return NULL;
	
	char* pResult = new char[nLen] {};
	WideCharToMultiByte(CP_ACP, 0, szStr, -1, pResult, nLen, NULL, NULL);
	return pResult;
}

CPPEX_API bool NP_CPPEX::IsPath(const char* szStr)
{
	std::tr2::sys::path tmpPath;

	return false;
}

CPPEX_API bool NP_CPPEX::IsFile(const char* szStr)
{
	std::tr2::sys::path tmpPath;
	return false;
}





//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

const wchar_t* wszConsoleTitle = L"UsbMultiUpdate";

NP_CPPEX::CMyToolLog::CMyToolLog()
{
	m_pIn = nullptr;
	m_pOut = nullptr;
	m_pErr = nullptr;
	m_bConsole = false;
	CreateConsoleLog();
}

NP_CPPEX::CMyToolLog::~CMyToolLog()
{
	DestroyConsoleLog();
}

void NP_CPPEX::CMyToolLog::CreateConsoleLog(const char* chLogfilepath /*= nullptr*/)
{
	// 检查glog 加载
	if (!m_bConsole)
	{
		m_bConsole = true;

		m_pIn = stdin;
		m_pOut = stdout;
		m_pErr = stderr;

		AllocConsole();
		SetConsoleTitle(wszConsoleTitle);
		freopen_s(&m_pIn, "CONIN$", "r+t", stdin);
		freopen_s(&m_pOut, "CONOUT$", "w+t", stdout);
		freopen_s(&m_pErr, "CONOUT$", "w+t", stderr);

		google::InitGoogleLogging("test glog");
		google::SetStderrLogging(google::GLOG_INFO);

		FLAGS_logtostderr = true;
		FLAGS_colorlogtostderr = true;

		FLAGS_logbufsecs = 0; // 设置可以缓冲日志的最大秒数 （0 实时输出）
							  // FLAGS_stop_logging_if_full_disk = true;
							  // FLAGS_log_prefix = true; // 设置日志前缀是否应该添加到每行输出

							  // 目录必须是已经创建的
		FLAGS_log_dir = "D:\\";
	}
}

void NP_CPPEX::CMyToolLog::DestroyConsoleLog()
{
	google::ShutdownGoogleLogging();

	fclose(stdin);
	fclose(stdout);
	fclose(stderr);
}

void NP_CPPEX::CMyToolLog::LOGINFO(const char* szLoginfo)
{
	LOG(INFO) << szLoginfo;
}

void NP_CPPEX::CMyToolLog::LOGWARRING(const char* szLogWarring)
{
	LOG(WARNING) << szLogWarring;
}

void NP_CPPEX::CMyToolLog::LOGERROR(const char* szLogError)
{
	LOG(ERROR) << szLogError;
}
