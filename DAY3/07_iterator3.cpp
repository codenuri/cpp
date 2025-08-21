#include <iostream>
#include <array>

int main()
{
	std::array<int, 10> arr = { 1,2,3,4,5,6,7,8,9,10 };

	// arr 의 모든 요소를 순회 하는 방법
	// 1. 제일 좋은 방법 - range-for
	for( auto e : arr)
	{
		std::cout << e << ", ";
	}


	// 2. 반복자 사용
	auto first = arr.begin();
	auto last = arr.end();

//	while( fist != last )
	while( fist != first + 5 )
	{
		auto e = *first; // first 는 반복자, 즉, 포인터와 동일한 사용법
		++first; // first += 2
	}

	// 일부 구간만 순회등의 작업이 필요하면 2번 사용
}