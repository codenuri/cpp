// 1_레퍼런스.cpp    58 page ~

#include <iostream>

int main()
{
	int n1 = 10;

	int* p1 = &n1;
	int& r1 = n1; // reference
				  // 기존 변수에 또다른 이름(alias)를 부여 하는 것

	r1 = 30;

	std::cout << n1  << std::endl; // 30
	
	std::cout << &r1 << std::endl; // 이 코드의 실행결과(주소)는 아래 코드 결과와 동일
	std::cout << &n1 << std::endl; 

	// 핵심 #1. reference 만드는 법
	// 핵심 #2. reference 의미 : 기존 변수에 또 다른 이름을 부여 한것
	// 주의 사항

	// #1. & 연산자에 대해서
	int* p2 = &n1; // 이 경우의 & 는 주소 연산자
	int& r2 = n1;  // 이 경우의 & 는 reference 연산자

	// #2. 
	// 포인터 변수 : 주소로 초기화
	// reference : 변수 이름으로 초기화
}



