#include <iostream>

// 방법 #2. strategy
// => 변하는 것을 다른 클래스로
// => 메모리 할당/해지 를 책임지는 별도의 클래스 작성
// => 교체 가능해야 하므로 인터페이스 필요

template<typename T>
struct IAllocator
{
	virtual T* allocate(std::size_t sz) = 0;
	virtual void deallocate(T* ptr, std::size_t sz) = 0;
	virtual ~IAllocator() {}
};


template<typename T>
class vector
{
	T* buff;
	std::size_t size;
public:
	void resize(int sz)
	{
		buff = new T[sz];

		delete[] buff;
	}
};

int main()
{
}