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

// 디자인 관점에서 iterator 의 특징
// => 모든 종류의 컨테이너(컬렉션)을 동일한 방법으로 이동한다는 것
// => vector, list, array, set 등의 모든 컨테이너에는 반복자가 있습니다.
// => 반복자만 꺼내면 동일한 방식으로 일거 가능. 

// => C#/Java/C++/Python/Rust 등 거의 모든 언어에 있는 개념. 