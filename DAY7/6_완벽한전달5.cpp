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
	// 아래 캐스팅은 항상 rvalue 캐스팅이 아닙니다.

	// chronometry 의 2번째 인자로 
	// rvalue(10) 을 전달하면 ( arg 로 받으면서 lvalue 로 변한것을 다시) rvalue로 캐스팅
	// lvalue(n)  을 전달하면 (필요없는 캐스팅 이지만)                   lvalue 로 캐스팅
	
//	f(static_cast<T&&>(arg)); 	// 이렇게 해도 완벽한 코드지만

	f( std::forward<T>(arg));   // C++ 표준은 "std::forward<>()" 함수 사용을 권장
								// 내부적으로 위와 동일하게 캐스팅 수행
								// <T&&> 가 아닌 <T>로 전달, 내부적으로 && 붙여서 사용
}

int main()
{
	int n = 0;

	chronometry(foo, 10); // T = int   T&& = int&&
						  // static_cast<int&&>(arg)

	chronometry(goo, n);  // T = int&   T&& = int& && => int& 
						  // static_cast<int&>(arg)

}
