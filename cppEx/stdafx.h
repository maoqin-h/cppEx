// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // �� Windows ͷ���ų�����ʹ�õ�����
// Windows ͷ�ļ�: 
#include <windows.h>



// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�
#include <filesystem>


#define GOOGLE_GLOG_DLL_DECL
#define GLOG_NO_ABBREVIATED_SEVERITIES
#include "glog/logging.h"


#ifdef _DEBUG
#ifdef _MT
#ifdef _DLL
#pragma comment(lib, "glog/lib/glogd.lib")
#else
#pragma comment(lib, "glog/lib/glogMTd.lib")
#endif
#endif
#else
#ifdef _MT
#ifdef _DLL
#pragma comment(lib, "glog/lib/glog.lib")
#else
#pragma comment(lib, "glog/lib/glogMT.lib")
#endif
#endif
#endif


