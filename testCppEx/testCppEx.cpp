// testCppEx.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
using std::endl;
using std::cout;

template <typename T, typename U>
auto add(T t, U u) -> decltype(t + u) {
	// 返回值在 后面了
	return t + u;
}

int main()
{
	TOOL_LOGINSTANCE;

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
		// decltype 推导表达式类型
		decltype(i) b = 2;

		int a = 0, b1 = 0;
		decltype(a + b1) c = 0; // a + b1 是右值 ，c 是 int
		decltype(a += b1) d = c;// a+=b1 返回左值， d 是 int&
		d = 20;
		cout << c << endl; // 20
		add(3, 3.0);
		auto func_tmp = add<int, char>;
	};
	//test_func2();

	auto test_func3 = []() {
		TOOL_LOGINFO("this is info log");
		TOOL_LOGWARNING("this is warning log");
		TOOL_LOGERROR("this is error log");
	};
	test_func3();


	system("pause");
    return 0;
}

