#include <iostream>

// 아래 구조체를 생각해 보세요

template<typename T, unsigned int N>
struct array 
{
	T buff[N];

	int size() const { return N;}
	bool empty() const { return N == 0;}
};

int main()
{
	// 아래 arr 의 메모리 구조는 5개 배열과 완벽히 동일합니다.
	array<int, 5> arr = {1,2,3,4,5};

	// 하지만 배열은 멤버 함수가 없지만, 위 array 은 멤버 함수가 있어서 편리합니다.
	std::cout << arr.size() << std::endl;
}

