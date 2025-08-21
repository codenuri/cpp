#include <iostream>
#include <algorithm>
#include <array>

bool foo(int e) 
{
	return e % 3 == 0;
}
int main()
{
	std::array<int, 10> arr = { 1,2,6,4,5,3,7,8,9,10 };


	// 주어진 구간에서 "3"을 찾고 싶다.
	auto ret1 = std::find(arr.begin(), arr.end(), 3); 


	// 주어진 구간에서 "3의 배수"을 찾고 싶다.
	auto ret2 = std::find_if(arr.begin(), arr.end(),  foo ); 	
	std::cout << *ret2 << std::endl; // 6

	// std::find   (first, last, 값)      : 값 검색
	// std::find_if(first, last, 조건함수) : 조건을 만족하는 값 검색
}