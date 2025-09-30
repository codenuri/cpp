#include <iostream>

// 완벽한 전달을 이해하기 위한 사전지식
void foo(int& a)		{ std::cout << "int&" << std::endl; }
void foo(int&& a)		{ std::cout << "int&&" << std::endl; }

int main()
{
	int n = 10;
	foo(n);		// int&
	foo(10);	// int&&

	int& r1 = n;
	foo(r1);	// int&

	int&& r2 = 10;
	foo(r2);	// int& <= 핵심!!

	// 핵심 : 타입과 value category 를 헷갈리지 마세요

	//Point pt{1,1};

	//					type		value category
	// n				int			lvalue
	// 3				int			rvalue
	// pt				Point		lvalue
	// Point{1,1}		Point		rvalue
	// r1				int&		lvalue
	// r2				int&&		lvalue   <== 타입은 int&& 지만, value 속성은 lvalue

	// foo(int&)  : int&  타입을 받겠다는 것이 아니라 lvalue 를 받겠다는 의미
	// foo(int&&) : int&& 타입을 받겠다는 것이 아니라 rvalue 를 받겠다는 의미
	
	foo(r2); // lvalue 이므로 int&
	foo(static_cast<int&&>(r2)); // lvalue => rvalue 로 캐스팅..
								 // 따라서, foo(int&&) 버전 호출

}







