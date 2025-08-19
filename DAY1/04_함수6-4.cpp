#include <iostream>

// 함수는 "입력"이 먼저 "출력" 이 나중입니다.
// 그런데, 전통적인 C 스타일은
// "출력타입"  함수이름 (입력 인자) 형태 입니다.
// 논리적으로 잘못된 표기법

// "함수이름(입력) -> 출력" 이 맞는 표기법

template<typename T1, typename T2>
//decltype(a + b) add(T1 a, T2 b) 
auto add(T1 a, T2 b) -> decltype(a + b) // ok. a, b 를 선언후 사용!!!
{
	return a + b;
}

int main()
{ 
	std::cout << add(1.1, 2) << std::endl; 
	
}
