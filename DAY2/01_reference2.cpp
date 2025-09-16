// 1_레퍼런스2
#include <iostream>
// 어렵지는 않지만 반드시 알아야 하는 중요한 내용

void inc1(int n)  { ++n; }
void inc2(int* p) { ++(*p); }
void inc3(int& r) { ++r; }

int main()
{
	int a = 1, b = 1, c = 1;

	inc1( a ); // call by value, a 값 증가 실패
	inc2( &b); // call by pointer, b 값 증가 성공
	inc3( c ); // call by reference, c값 증가 성공

	std::cout << a << std::endl; // 1
	std::cout << b << std::endl; // 2
	std::cout << c << std::endl; // 2
}
// 핵심 #1. 위 코드 실행시 메모리 그림 반드시 알아야 합니다.
// 핵심 #2. inc2 와 inc3 중 어떤 코드가 좋은 코드 일까요 ?
