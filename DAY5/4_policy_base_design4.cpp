#include <iostream>

// 방법 #3. policy base design

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

	IAllocator<T>* alloc = nullptr;
public:
	void set_allocator(  IAllocator<T>* p) { alloc = p;}

	void resize(int sz)
	{
		buff = alloc->allocate(sz); 

		alloc->deallocate(ptr, sz);
	}
};

template<typename T>
class malloc_allocator : public IAllocator<T>
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
	vector<int> v;
	malloc_allocator<int> ma;

	v.set_allocator(&ma); 
	v.resize(10);
}