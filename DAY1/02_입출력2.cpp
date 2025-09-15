// 3_입출력2.cpp - 18 page
#include <iostream>
#include <iomanip> // std::setw, std::setfill

// std::hex, std::dec, std::setw 등을 "입출력 조정자(iomanipulator)" 라고 합니다.
// <iostream> 헤더 또는 <iomanip> 헤더에 있습니다.

int main()
{
	int n = 10;
	
	std::cout << n << std::endl; // 10,  10진수 출력

	std::cout << std::hex << n << std::endl; // a, 16진수로 출력
	
	std::cout << std::dec << n << std::endl; // 10

	std::cout << std::setw(10) << std::setfill('#') << n << std::endl; 
							// ########10
}
