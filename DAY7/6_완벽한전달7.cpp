#include <iostream>
#include <string>

void f0() {}
void f1(int a) {}
void f2(int a, double d) {}
void f3(int& a, double d, const std::string& s ) {}

// 인자 한개가 아닌 모든 형태의 인자(여러개이거나 없거나)를 완벽한 전달하려면
// => 가변인자 템플릿 사용

template<typename F, typename ... T>
void chronometry(F f, T&& ... arg)	
{
	f( std::forward<T>(arg)... );   
}
int main()
{
	int n = 0;

	chronometry(f0);
	chronometry(f1, 2);
	chronometry(f2, 2, 3.4);
	chronometry(f3, n, 3.4, "hello");
						  

	chronometry(goo, n);  

}
