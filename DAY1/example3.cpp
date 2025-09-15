#include <iostream>

// 핵심 : ? 를 어떻게 표기해야 할까요 ?
/*
template<typename T1, typename T2>
? Add(T1 a, T2 b)
{
	return a + b;
}
	*/

// 해결책 : decltype() 사용. 
// => 이럴때 사용하기 위해 만든 키워드.
// => 그런데, 아래 코드가 에러 입니다. 왜?? 에러 일까요 ? 이유를 생각해 보세요
// => a, b 를 선언 전에 사용하는 코드. 
/*
template<typename T1, typename T2>
decltype(a + b) Add(T1 a, T2 b)
{
	return a + b;
}
*/

// 해결책 : suffix return type!!
// => 출력표현시에 "입력 변수를 사용" 하는 것은 논리적으로 가능 해야 합니다
template<typename T1, typename T2>
auto Add(T1 a, T2 b) -> decltype(a + b)
{
	return a + b;
}


int main()
{
	std::cout << Add(1, 2.1)   << std::endl; 

	a = 20; // error. 선언전 사용했으므로. 
	int a = 10;
	a = 20; // ok, 선언후 사용
}