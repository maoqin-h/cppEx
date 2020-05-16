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
