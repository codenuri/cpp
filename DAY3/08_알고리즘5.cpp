#include <iostream>
#include <vector>
#include <array>

int main()
{
	std::array<int, 10> arr = { 1,2,3,4,5,6,7,8,9,10 };
		
	// arr 에서 짝수를 0 으로 변경해 보세요	 
	// std::replace_if() 사용하면 됩니다 - 알고리즘2.cpp 참고
	
	// std::replace   (first, last, 값,       값);
	// std::replace_if(first, last, 조건함수, 값);

//	std::replace_if( arr.begin(), arr.end(), 짝수조사함수, -1);
	std::replace_if( arr.begin(), arr.end(), [](int n) { return n % 2 == 0;}, 0);


	for (auto e : arr)
		std::cout << e << ", "; // 1,0,9,0,3,0,7,3,9,0
}