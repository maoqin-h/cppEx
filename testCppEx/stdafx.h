// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�
#include "../cppEx/ICppEx.h"
#include "../cppEx/cppEx.h"


#ifdef _DEBUG
#pragma comment(lib, "../Debug/cppEx_d.lib")
#else
#pragma comment(lib, "./Release/cppEx.lib")
#endif 
