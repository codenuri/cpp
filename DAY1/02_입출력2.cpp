// 3_입출력2.cpp - 18 page
#include <iostream>
#include <iomanip>  // std::setw(), std::setfill() 

// 조정자 함수(iomanipulator)
// => std::cout 출력시 화면 출력 방식을 지정하는 것
// => std::hex, std::dec, std::setw, std::setfill 등
// => <iostream> 에 있는 것도 있고
// => <iomanip>  에 있는 것도 있습니다.

int main()
{
	int n = 10;

	std::cout << n << std::endl; // 10 즉, 10진수 출력

	std::cout << std::hex << n << std::endl; // a,  16진수 출력

	std::cout << std::dec << n << std::endl; // 


	std::cout << std::setw(10) << std::setfill('#') <<  n << std::endl; // 
}
