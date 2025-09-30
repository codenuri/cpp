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
// hoo(10)	=======================================================> ok
// chronometry(10)  ============> int&& arg 로 받는다
//								  이때 arg 는 lvalue
//								  foo(arg) ========================> error
//								  foo(static_cast<int&&>(arg)) ====> ok
template<typename F>
void chronometry(F f, int&& arg)	// int&& arg = 10
{
	// int&& arg = 10 으로 받게되는데, 이때
	// arg는 이름이 있으므로 lvalue 이다.!
	// 즉, 10이라는 rvalue 를 받으면서, 이름이 생겨서, lvalue 가 되었다.
//	f(arg);	 	// hoo(lvalue) 를 찾게 된다.

	// 해결책 : 받으면서 lvalue 된것을 다시 rvalue 로 캐스팅
	f(static_cast<int&&>(arg)); // ok. hoo(int&&)
}

int main()
{
	hoo(10); 

	chronometry(hoo, 10); 
}
