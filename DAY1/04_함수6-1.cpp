#include <iostream>

// 아래 템플릿은 1, 2번째 인자가 항상 같은 타입이어야 한다.
// => 하지만 C/C++은 "int + double" 도 가능한 언어 이다.
template<typename T>
T add(T a, T b)
{
	return a + b;
}

int main()
{
	std::cout << add(1,   2) << std::endl;

	std::cout << add(1.1, 2) << std::endl;  // 컴파일 에러, T 를 추론 못함

	std::cout << add<double>(1.1, 2) << std::endl;  // ok. T = double!!
							// 하지만 이경우, 2 => double 로 암시적 변환 되어 전달
							// 그리고, 항상 타입을 지정해야 하므로 불편!!
}
