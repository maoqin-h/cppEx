// cppEx.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "cppEx.h"


//// ���ǵ���������һ��ʾ��
//CPPEX_API int ncppEx=0;
//
//// ���ǵ���������һ��ʾ����
//CPPEX_API int fncppEx(void)
//{
//    return 42;
//}
//
//// �����ѵ�����Ĺ��캯����
//// �й��ඨ�����Ϣ������� cppEx.h
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
	// ���glog ����
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

		FLAGS_logbufsecs = 0; // ���ÿ��Ի�����־��������� ��0 ʵʱ�����
							  // FLAGS_stop_logging_if_full_disk = true;
							  // FLAGS_log_prefix = true; // ������־ǰ׺�Ƿ�Ӧ����ӵ�ÿ�����

							  // Ŀ¼�������Ѿ�������
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
