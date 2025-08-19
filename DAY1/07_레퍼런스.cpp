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
// 주의 사항
// #1. & 연산자
// int* p = &n;  // 여기서 & 는 주소 연산자
// int& r = n;   // 여기서 & 는 주소 연산자가 아닌 reference 연산자
			  // 즉 동일한 & 연산자가 다른 의미를 가진것
			  // * 가 곱셈 또는 포인터 연산자가 되듯이. 하나의 연산자가 2가지 용도

// #2. 포인터 를 초기화 할때는  주소(&n) 로
//     reference 를 초기화 할때는 변수 이름만(n)!!
// => 위 코드 참고. 

