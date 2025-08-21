#include <iostream>
#include <algorithm>
#include <array>

int main()
{
	std::array<int, 10> arr = { 1,2,3,4,5,6,7,8,9,10 };

	// find 사용법
	// find(first, last, 값) : last 는 검색 대상 아님.
	//							[first, last) 라고 표현 
	// 검색 성공시 : 요소의 위치를 가리키는 반복자
	//     실패시 : last 반환

//	auto ret1 = std::find(arr.begin(), arr.end(), 3); 
	auto ret1 = std::find(arr.begin(), arr.end(), 13); 

	// 따라서, 검색 실패를 조사하려면 
	// 반환값을 last 와 비교하세요
	if (ret1 == arr.end())
	{
		std::cout << "검색실패\n";
	}
	else
	{
		std::cout << *ret1 << std::endl;
	}
}