#pragma once


#ifdef CPPEX_EXPORTS
#define CPPEX_API __declspec(dllexport)
#else
#define CPPEX_API __declspec(dllimport)
#endif

