#include <iostream>


template<typename T>
T Add(T a, T b)
{
	return a + b;
}

int main()
{
	// 핵심 : 아래 코드가 에러인 이유를 정확히 알아야 합니다.
	// 타입인자가 생략 되었으므로 인자를 보고 T를 추론해야 하는데
	// 1 은 int, 2.1 은 double 이므로 타입 추론 실패. 
	std::cout << Add(1, 2.1)   << std::endl; 

	// 아래 처럼 사용하면 에러는 아닙니다.
	// => 그런데, 타입을 매번 표기해야 하므로 불편하고
	// => 1, 2의 타입이 결국 항상 같은 타입으로 받게 됩니다.
	std::cout << Add<double>(1, 2.1)   << std::endl; 
	
}