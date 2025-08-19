// 1_레퍼런스.cpp    58 page ~

#include <iostream>

int main()
{
	int n1 = 10;
	
	int* p1 = &n1; // C 언어 포인터

	int& r1 = n1;   // C++ reference
					// 기존 변수에 대한 별명을 만드는 것

	r1 = 30;	// 결국 n1 = 30 의 의미

	std::cout << n1  << std::endl; // 30
	
	std::cout << &r1 << std::endl;	// 이 결과는 
	std::cout << &n1 << std::endl;	// 이 결과와 동일합니다.
}



