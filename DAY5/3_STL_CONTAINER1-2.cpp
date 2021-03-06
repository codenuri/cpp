// 3_STL_CONTAINER1-2
#include <iostream>
#include <array> // 아래 모양과 유사한 클래스 템플릿
				 // C++11부터 지원
template<typename T, int N> 
struct array
{
	T x[N];

	inline int size() const { return N; }
};

int main()
{
	std::array<int, 10> a = { 1,2,3,4,5,6,7,8,9,10 };

	std::cout << a.size() << std::endl;

	// std::array 는 크기조절은 할수 없습니다. 
	// resize 멤버 함수 없음.
}