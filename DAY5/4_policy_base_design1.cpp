#include <iostream>

// STL 의 vector 를 생각해 봅시다.

template<typename T>
class vector
{
	T* buff;
	std::size_t size;
public:
	void resize(int sz)
	{
		// resize 구현을 위해서 메모리 재할당이 필요하다고 가정해 봅시다.
		// 어떤 방법으로 메모리를 할당하면 좋을까요 ?
		// new / malloc / system call / windows api ?

		// 아래 처럼 코드를 작성하면
		// 메모리 할당/해지 하는 방법을 교체 할수 없습니다.
		// => 메모리 할당/해지가 가능한 최고의 디자인을 찾아 봅시다.(결국 STL 원리)
		buff = new T[sz];

		delete[] buff;
	}
};

int main()
{
}