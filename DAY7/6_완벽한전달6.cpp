#include <iostream>

void foo(int a)  {}
void goo(int& a) { a = 100; }
void hoo(int&& a) {}

// 인자 한개를 완벽한 전달하려면
// 1. 인자를 받을때는 T&& 사용
// 2. 받은 인자를 다른 함수에 전달(forward)할때는 "std::forward<T>(arg)" 로 묶어서 전달. 

template<typename F, typename T>
void chronometry(F f, T&& arg)	
{
	f( std::forward<T>(arg) );   
}

int main()
{
	int n = 0;

	chronometry(foo, 10); 
						  

	chronometry(goo, n);  

}
