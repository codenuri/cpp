#include <iostream>

// 방법 #3. policy base design


template<typename T, typename Alloc>
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
	vector<int, malloc_allocator<int>> v; // template 2번째 인자로 메모리 할당기 전달
	
	v.resize(10);
}