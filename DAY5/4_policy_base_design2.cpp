#include <iostream>

// 변하지 않은 vector 구현 코드에서
// "메모리 할당/해지" 부분만 분리하고 싶은 것

// 방법 #1. template method 패턴
// => 변하는 것을 가상함수로 분리하는것
// => 메모리 할당/해지를 책임지는 가상함수를 만들어서 사용

// 단점 : malloc_vector 가 메모리 할당하는 알고리즘을 소유!!
// => list, map, set 등 다른 컨테이너에 재사용 안됨
// => malloc_list 를 만들어서 동일한 코드를 다시 작성해야 합니다.

// => 즉, vector 기능과 메모리 할당 기능이 분리되지 않음. 


template<typename T>
class vector
{
	T* buff;
	std::size_t size;
public:
	void resize(int sz)
	{
		buff = allocate(sz);
		deallocate(buff, sz);
	}
	// 변하는 것(메모리할당/해지)를 책임지는 가상함수
	// => 이제 vector 의 모든 멤버 함수에서는 메모리 할당/해지가 필요 할때 마다 아래 가상함수 사용
	virtual T*   allocate(std::size_t sz)           { return new T[sz];}
	virtual void deallocate(T* ptr, std::size_t sz) { delete[] ptr;}
};

template<typename T>
class malloc_vector : public vector<T>
{
public:
	T*   allocate(std::size_t sz) override 
	{ 
		void* p = malloc(sizeof(T) * sz);
		return static_cast<T*>(p);
	}
	void deallocate(T* ptr, std::size_t sz) override 
	{
		free(ptr); 
	}
};

int main()
{
	malloc_vector<int> v; // malloc 을 사용하는 vector
	v.resize(10);
}