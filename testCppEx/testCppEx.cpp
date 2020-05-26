// testCppEx.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdlib.h>
#include <iostream>

using std::endl;
using std::cout;

NP_CPPEX::CMyToolLog g_myLog;


// test2
/*
template <typename T, typename U>
decltype(t + u) add(T t, U u)
{
// ����ֵ������������ t, u ֮�⣬Ҳ�� ֮ǰ��
return t + u;
}

*/

template <typename T, typename U>
auto add(T t, U u) -> decltype(t + u) {
	// ����ֵ�� ������
	return t + u;
}

int main()
{
	auto test_func1 = []() {
		NP_CPPEX::CMyToolLog::LOGINFO("this is loginfo 123456");
		NP_CPPEX::CMyToolLog::LOGINFO("this is loginfo 654321");
		NP_CPPEX::CMyToolLog::LOGWARNING("this is warning 654321");
		NP_CPPEX::CMyToolLog::LOGERROR("this is error 654321");
		OutputDebugString(L"ssss");

	};
	//test_func1();

	auto test_func2 = []() {
		const int& i = 1;
		// decltype �Ƶ����ʽ����
		decltype(i) b = 2;

		int a = 0, b1 = 0;
		decltype(a + b1) c = 0; // a + b1 ����ֵ ��c �� int
		decltype(a += b1) d = c;// a+=b1 ������ֵ�� d �� int&
		d = 20;
		cout << c << endl; // 20
		add(3, 3.0);
		auto func_tmp = add<int, char>;
	};
	test_func2();



	system("pause");
    return 0;
}

