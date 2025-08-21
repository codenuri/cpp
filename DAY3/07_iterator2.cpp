#include <iostream>
#include <array>

int main()
{
	std::array<int, 10> arr = { 1,2,3,4,5,6,7,8,9,10 };
	
	// 1. past the end

	auto p1 = arr.begin();	// 1번째 요소(1)을 가리키는 반복자
	auto p2 = arr.end();	// 마지막이 아닌 마지막 다음요소를 가리키는 반복자 <== 핵심. 	 

	*p1 = 10;	// ok
//	*p2 = 10;	// runtime- error. .end()로 얻은 반복자는 * 연산하면 안됩니다.

	// .end()로 얻은 것은 언제 사용하나요 ??
	// 아래 처럼 p1 부터 ++로 이동시, 마지막 도착을 확인하는 용도로만 사용
	
	while (p1 != p2)
	{
		std::cout << *p1 << std::endl;
		++p1;
	}
}