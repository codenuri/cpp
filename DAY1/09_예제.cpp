#include <iostream>

// Swap를 만들어 봅시다.
// 1. C 버전
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

// C++ 버전
// 1. 포인터 대신 레퍼런스
// 2. 함수 대신 함수를 만드는 틀(template) 제공
// 3. 간단한 함수라면 inline
// 4. 규모가 큰 프로젝트에서 사용시, 이름 충돌을 막기 위해서 namespace 로 분리
// 5. 만들필요없다.. 이미 C++ 표준에 있다.
namespace util
{
	template<typename T> 
	inline void Swap(T& a, T& b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	}
}
int main()
{
	int x = 3, y = 2;
//	Swap(&x, &y);
//	util::Swap(x, y);
	std::swap(x, y);

	std::cout << x << std::endl;
	std::cout << y << std::endl;
}



