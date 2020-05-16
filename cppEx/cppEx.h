//#include "ICppEx.h"

#ifdef CPPEX_EXPORTS
#define CPPEX_API __declspec(dllexport)
#else
#define CPPEX_API __declspec(dllimport)
#endif
//// 此类是从 cppEx.dll 导出的
//class CPPEX_API CcppEx {
//public:
//	CcppEx(void);
//	// TODO:  在此添加您的方法。
//};
//
//extern CPPEX_API int ncppEx;
//
//CPPEX_API int fncppEx(void);



namespace NP_CPPEX
{
	// 字符转换
	CPPEX_API inline wchar_t* AnsiToUnicode(const char* szStr);
	CPPEX_API inline char* UnicodeToAnsi(const wchar_t* szStr);

	// 文件路径
	CPPEX_API bool IsPath(const char* szStr);
	CPPEX_API bool IsFile(const char* szStr);


	class CPPEX_API CMyToolLog
	{
	public:
		CMyToolLog();
		virtual ~CMyToolLog();

		static void LOGINFO(const char* szLoginfo);
		static void LOGWARNING(const char* szLogWarning);
		static void LOGERROR(const char* szLogError);

	protected:
		void CreateConsoleLog(const char* chLogfilepath = nullptr);
		void DestroyConsoleLog();

	private:
		bool	m_bConsole;			// 已创建console
		FILE*	m_pIn;
		FILE*	m_pOut;
		FILE*	m_pErr;
	};
	
}
