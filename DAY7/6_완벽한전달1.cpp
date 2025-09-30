#include <iostream>

void foo(int a)  {}
void goo(int& a) { a = 100; }

// 함수의 성능을 측정하는 함수
template<typename F>
void chronometry(F f, int arg)
{
	// <============== 현재 시간 기록
	f(arg);	 // <===== 함수 호출
	// <============== 다시 시간을 구해서 걸린시간 출력
}

int main()
{
	int n = 10;

	chronometry(foo, 10); // foo(10);
	chronometry(goo, n);  // goo(n);

	std::cout << n << std::endl;
}
