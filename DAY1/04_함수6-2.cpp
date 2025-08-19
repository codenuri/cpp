#include <iostream>

template<typename T1, typename T2>
? add(T1 a, T2 b)
{
	return a + b;
}

int main()
{
	// 아래 코드는 타입을 전달한것
	std::cout << add<double, int>(1.1, 2) << std::endl;

	// 아래 코드는 타입을 전달하지 않아서, 인자로 타입 추론하는 것 
	std::cout << add(1.1, 2) << std::endl; // ok
					// T1 = double, 
					// T2 = int 로 추론
					// 그런데... 위 코드에서 ?? 어떻게 해야할까 ??
					// 이 부분이 이 예제의 핵심!!!! 어려운 문제
}
