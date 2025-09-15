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

	double d = 0.1234567890;

	std::cout << d << std::endl; // 몇자리까지 출력되는지 확인해 보세요
								 // => 0.123457, 즉, 소수점 6자리에서 반올림해서 출력

	// 소수점 이하 10자리 까지 모두 출력해 보세요
	// => 소수점의 정밀도를 지정하는 "iomanipulator" 를 사용해야 합니다.
	// 1. cppreference.com 에 접속하세요
	// 2. 우측 상단의 검색에서 "std::setw" 검색후, 선택
	// 3. std::setw 문서에서 "상위문서" 로 이동

	std::cout << std::setprecision(10) << d << std::endl;
}
