#include <iostream>

void foo(int a)  {}
void goo(int& a) { a = 100; }

void hoo(int&& a) {}


template<typename F>
void chronometry(F f, int& arg)
{
	f(arg);	 
}

template<typename F>
void chronometry(F f, int&& arg)
{
	f(arg);	 
}

int main()
{
	hoo(10); // ok

	chronometry(hoo, 10); // error. 왜 에러 일까요 ?
						  // 에러가 나오는 소스 보관하고(복습시 사용)
						  // 원인과 해결은 다음소스에서 
}
