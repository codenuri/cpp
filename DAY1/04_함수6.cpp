#include <iostream>

// 아래 처럼만 하면 int 2개만 가능
/*
int add(int a, int b)
{
	return a + b;
}
*/

// 아래 처럼하면 모든 타입에 대해서 함수 생성가능
template<typename T>
T add(T a, T b)
{
	return a + b;
}

int main()
{
	std::cout << add(1,   2  ) << std::endl;
	std::cout << add(1.1, 2.2) << std::endl; // ???
}