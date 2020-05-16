#include "ICppEx.h"
#include <filesystem>


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
}
