#include <iostream>

// const_cast : 

int main()
{
	const int c = 10;

	int* p1 = (int*)&c; // A

	// 위 캐스팅이 된다면 아래 처럼 c의 값도 변경할수 있다는것!
	*p1 = 20;

	// 아래 코드 결과 예측해 보세요???
	std::cout << c   << std::endl; // 10 이지만, 이 결과는 컴파일러 종류에 따라
									//			 다를수 있습니다.
									// 			A 캐스팅은 너무 위험합니다.
	std::cout << *p1 << std::endl; // 20
}
