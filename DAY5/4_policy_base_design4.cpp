#include <iostream>

// 방법 #3. policy base design
// => 정책을 담을 클래스를 "인터페이스 기반"이 아닌 템플릿 인자로 교체 하자는 것

// 장점 : 정책 함수가 가상함수가 아닌 인라인 함수이다. 빠르다.
// 단점 : 템플릿 인자이므로 실행시간에 정책 교체 안됨. 

// strategy : e.set_validate(v1); 
//			  e.set_validate(v2);  // 실행시간 교체됨

// policy base design : vector<int, malloc_allocator<int>>  에서 
//										allocator 는 실행시간 교체 안됨. 


// std::allocator<T>  : C++ 표준 메모리 할당기. 이미 C++ 표준에서 메모리 할당기를 제공
// => new/delete 로 메모리 할당/해지
template<typename T, typename Alloc = std::allocator<T> >
class vector
{
	T* buff;
	std::size_t size;

//	malloc_allocator<T> alloc; // 강한 결합. 교체 안됨.
	Alloc alloc;			   // template 인자로 전달한 타입 사용. 즉, 템플릿 인자로 교체
public:
	void resize(int sz)
	{
		buff = alloc.allocate(sz); 
		alloc.deallocate(ptr, sz);
	}
};

template<typename T>
class malloc_allocator 
{
public:
	inline T*   allocate(std::size_t sz) 
	{ 
		void* p = malloc(sizeof(T) * sz);
		return static_cast<T*>(p);
	}
	inline void deallocate(T* ptr, std::size_t sz)
	{
		free(ptr); 
	}
};
int main()
{	
//	vector<int, malloc_allocator<int>> v; // template 2번째 인자로 메모리 할당기 전달
	vector<int> v; 	// 표준 할당기 사용
	
	v.resize(10);
}