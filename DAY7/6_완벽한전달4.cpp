#include <iostream>

void foo(int a)  {}
void goo(int& a) { a = 100; }

void hoo(int&& a) {}


template<typename F>
void chronometry(F f, int& arg)
{
	f(arg);	 
}

// main							chronometry						hoo(int&&)
// hoo(10)	=======================================================>

template<typename F>
void chronometry(F f, int&& arg)
{
	f(arg);	 
}

int main()
{
	hoo(10); 

	chronometry(hoo, 10); 
}
