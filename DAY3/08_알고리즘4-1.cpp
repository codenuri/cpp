#include <iostream>
#include <algorithm>
#include <array>

bool foo(int e) { return e % 3 == 0;}

int main()
{
	std::array<int, 10> arr = { 1,2,6,4,5,3,7,8,9,10 };


	// 조건함수로 "진짜 함수" 를 전달하는 기술
	auto ret1 = std::find_if(arr.begin(), arr.end(),  foo ); 

	// 조건 함수로 "람다표현식"을 전달하는 기술
	// 람다표현식 : [] 로 시작하는 표현식
	//             이름없는 함수를 만드는 기술

	auto ret2 = std::find_if(arr.begin(), arr.end(),  [](int e) { return e % 3 == 0;} ); 
		
}