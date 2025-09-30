#include <iostream>

void foo(int a)  {}
void goo(int& a) { a = 100; }

// perfect forwarding 하려면
// 1. 복사본이 없어야 한다.
// 2. int&, int&& 버전을 모두 제공해야 한다.
// => 그런데, 아래 코드는 단 한가지 경우에 에러 입니다.
// => 다음 소스에서 설명
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
	int n = 10;

	chronometry(foo, 10);
	chronometry(goo, n); 

	std::cout << n << std::endl;
}
