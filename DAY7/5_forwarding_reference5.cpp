#include <iostream>

template<typename T> void foo(T&& arg)
{
	
}
int main()
{
	int n = 10;

	// 복습 할때 현재 코드를 "godbolt.org" 에 넣으세요
	// 그리고 어셈 코드를 통해서 아래 주석처럼 만들어지는 것을 정확히 확인하세요. 
	foo(n);  //	T=int&, T&& = int& &&    foo(int&)
	foo(10); // T=int   T&& = int&&      foo(int&&)
}




