#include <iostream>

void foo(int a)  {}
void goo(int& a) { a = 100; }

void hoo(int&& a) {}

/*
template<typename F>
void chronometry(F f, int& arg)
{
//	f(arg);	 
	f(static_cast<int&>(arg));	 // int& 를 int& 로 캐스팅 하므로
								 // 필요없는 캐스팅. 
								 // 하지만 있어도 에러 아님.
								 // 컴파일 시간에 제거됨. 없는 것과 완전히 동일
}
template<typename F>
void chronometry(F f, int&& arg)	
{
	f(static_cast<int&&>(arg)); 
}
*/
// 결국 int 타입 인자 한개를 완벽한 전달을 하려면
// => int&, int&& 버전을 모두 만들어야 합니다.
// => 그런데, T&& 를 사용하면 int&, int&& 함수를 자동 생성할수 있습니다.

template<typename F, typename T>
void chronometry(F f, T&& arg)	
{
	f(static_cast<T&&>(arg)); 
}

int main()
{
	int n = 0;

	chronometry(foo, 10); // T = ?   T&& = ?
						  // static_cast<?>(arg)
						  
	chronometry(goo, n);  // T = ?   T&& = ?
						  // static_cast<?>(arg)

}
