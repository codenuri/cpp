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
template<typename T1, typename T2>
decltype(a + b) Add(T1 a, T2 b)
{
	return a + b;
}

int main()
{
	std::cout << Add(1, 2.1)   << std::endl; 

}