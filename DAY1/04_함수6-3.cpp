#include <iostream>

// decltype(표현식) : 컴파일 시간에 표현식의 최종 결과로 나오는 타입을 결정해 달라.
// => 주로 템플릿만들때 반환 타입을 표기하기 위해서 사용
// => 그런데 아래 코드는 에러!!! 왜 에러일까요 ?? 생각해 보세요

template<typename T1, typename T2>
decltype(a + b) add(T1 a, T2 b)
{
	return a + b;
}

int main()
{
 
	std::cout << add(1.1, 2) << std::endl; 
}
