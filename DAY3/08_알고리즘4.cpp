#include <iostream>
#include <algorithm>
#include <array>

int main()
{
	std::array<int, 10> arr = { 1,2,3,4,5,6,7,8,9,10 };

	// 주어진 구간에서 "3"을 찾고 싶다.
	auto ret1 = std::find(arr.begin(), arr.end(), 3); 


	// 주어진 구간에서 "3의 배수"을 찾고 싶다.
	auto ret2 = std::find(arr.begin(), arr.end(),  ?); 	
}