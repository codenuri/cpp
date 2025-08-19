// 1_레퍼런스2
#include <iostream>

// reference 를 사용하는 주된 용도
// => 함수 인자로 전달시 call by pointer 와 동일한 효과!!!
// => 그럼 call by pointer(inc2) 와 call by reference(inc3) 중에서 뭐가 좋나요 ?
// => 다음예제에서 생각해 봅시다.


void inc1(int n)  { ++n; }
void inc2(int* p) { ++(*p); }
void inc3(int& r) { ++r; }

int main()
{
	int a = 1, b = 1, c = 1;

	inc1( a ); // call by value, a증가 실패
	inc2( &b); // call by pointer, b증가 성공
	inc3( c ); // call by reference, c증가 성공

	std::cout << a << std::endl; // 1
	std::cout << b << std::endl; // 2
	std::cout << c << std::endl; // 2
}
