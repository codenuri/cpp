#include <iostream>
#include <array>
#include <algorithm> 

int main()
{
	std::array<int, 10> arr = { 1,2,3,4,5,6,7,8,9,10 };
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };

	// arr의 모든 요소를 뒤집어 보세요
	// => 멤버 함수가 아닌 일반 함수
	// => std::reverse()
	// => 대부분의 알고리즘의 인자는 반복자의 시작과 끝
	std::reverse(arr.begin(), arr.end());
	std::reverse(x, x + 10); // 진짜 배열도 가능. 주의 2번째 인자는 마지막 다음요소(x+10)
	

	for (auto e : arr)
		std::cout << e << ", ";
	std::cout << std::endl;

	// arr 에서 3 을 -1 로 변경해 보세요
	// std::replace() 알고리즘
	std::replace( arr.begin(), arr.end(), 3, -1);
	std::replace( x, x+10, 3, -1);
	

	for (auto e : arr)
		std::cout << e << ", ";
	std::cout << std::endl;

	
}