#include <iostream>

int main()
{
	const int c = 10;

//	int* p = &c;		// error. const int 주소를 int* 에 담을수 없다.
	int* p = (int*)&c; 	// ok. A

	// A가 컴파일된다면, 아래 처럼도 사용가능합니다.
	*p = 20; // ok!!

	std::cout << c  << std::endl; // 10
	std::cout << *p << std::endl; // 20
}
