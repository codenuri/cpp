#include <iostream>

// const_cast : 

int main()
{
	const int c = 10;

	int* p1 = (int*)&c; // ?

	*p1 = 20;

	// 아래 코드 결과 예측해 보세요???
	std::cout << c   << std::endl; // ?
	std::cout << *p1 << std::endl; // ?
}
