//#include "ICppEx.h"
#pragma once

#ifdef CPPEX_EXPORTS
#define CPPEX_API __declspec(dllexport)
#else
#define CPPEX_API __declspec(dllimport)
#endif


// 开启 TOOLLOG
//#define ENABLE_TOOLLOG

#if defined __cplusplus
extern "C" {
#endif 

	namespace NP_CPPEX
	{
		// 字符转换
		CPPEX_API inline wchar_t*  AnsiToUnicode(const char* szStr);
		CPPEX_API inline char*  UnicodeToAnsi(const wchar_t* szStr);

		// 文件路径
		CPPEX_API bool  IsPath(const char* szStr);
		CPPEX_API bool  IsFile(const char* szStr);

		class CPPEX_API CMyToolLog
		{
		public:
			static CMyToolLog& GetInstance();
			static void LOGINFO(const char* szLoginfo);
			static void LOGWARNING(const char* szLogWarning);
			static void LOGERROR(const char* szLogError);


		protected:
			CMyToolLog();
			virtual ~CMyToolLog();

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

#if defined __cplusplus
}
#endif 

#ifdef ENABLE_TOOLLOG
#define TOOL_LOGINSTANCE NP_CPPEX::CMyToolLog::GetInstance();
#define TOOL_LOGINFO( _strContext_ ) NP_CPPEX::CMyToolLog::LOGINFO(_strContext_);
#define TOOL_LOGWARNING( _strContext_ ) NP_CPPEX::CMyToolLog::LOGWARNING(_strContext_);
#define TOOL_LOGERROR( _strContext_ ) NP_CPPEX::CMyToolLog::LOGERROR( _strContext_);
#else
#define TOOL_LOGINSTANCE ;
#define TOOL_LOGINFO ;
#define TOOL_LOGWARNING ;
#define TOOL_LOGERROR ;
#endif 