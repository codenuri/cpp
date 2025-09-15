// example1.cpp

#include <iostream>

/*
int Add(int a, int b)
{
	return a + b;
}
*/
// 핵심 #1. int 대신 T를 사용하는 이유를 알아야 합니다.
// => int 뿐 아니라 double 도 Add 사용해서 정확한 결과를 얻기 위해
template<typename T>
T Add(T a, T b)
{
	return a + b;
}

int main()
{
	std::cout << Add(1,   2)   << std::endl;
	std::cout << Add(1.2, 2.1) << std::endl; // ?
}