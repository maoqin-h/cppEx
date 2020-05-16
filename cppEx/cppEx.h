#include "ICppEx.h"


//// �����Ǵ� cppEx.dll ������
//class CPPEX_API CcppEx {
//public:
//	CcppEx(void);
//	// TODO:  �ڴ�������ķ�����
//};
//
//extern CPPEX_API int ncppEx;
//
//CPPEX_API int fncppEx(void);


namespace NP_CPPEX
{
	// �ַ�ת��
	CPPEX_API inline wchar_t* AnsiToUnicode(const char* szStr);
	CPPEX_API inline char* UnicodeToAnsi(const wchar_t* szStr);

	// �ļ�·��
	CPPEX_API bool IsPath(const char* szStr);
	CPPEX_API bool IsFile(const char* szStr);


	CPPEX_API class CMyToolLog
	{
	public:
		CMyToolLog();
		virtual ~CMyToolLog();

		void CreateConsoleLog(const char* chLogfilepath = nullptr);
		void DestroyConsoleLog();
	private:
		bool	m_bConsole;			// �Ѵ���console
		FILE*	m_pIn;
		FILE*	m_pOut;
		FILE*	m_pErr;
	};
	
}
