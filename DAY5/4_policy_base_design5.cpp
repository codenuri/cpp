#include <iostream>
#include <vector>

// malloc_allocator 복사후 이름만 debug_alloc 으로
template<typename T>
class debug_alloc 
{
public:
	inline T*   allocate(std::size_t sz) 
	{ 
		void* p = malloc(sizeof(T) * sz);

		printf("[allocate] : %p, %u\n", p, sz);

		return static_cast<T*>(p);
	}
	inline void deallocate(T* ptr, std::size_t sz)
	{
		printf("[deallocate] : %p, %u\n", ptr, sz);
		free(ptr); 
	}
};



int main()
{
	// 실제 C++ 표준 vector 입니다.
//	std::vector<int> v;	// std::vector<int, std::allocator<int> > v; 입니다.
						// 즉, 표준 할당기를 사용하는 코드

	// vector 에 우리가 만든 메모리 할당기를 전달해 봅시다.
	std::vector<int, debug_alloc<int> > v; 

	std::cout << "-----------------" << std::endl;

	v.resize(5);

	std::cout << "-----------------" << std::endl;

	v.resize(10);	

	std::cout << "-----------------" << std::endl;
}
