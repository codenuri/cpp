#include <iostream>

void foo(int a)  {}
void goo(int& a) { a = 100; }

// perfect forwarding (완벽한 전달)
// => 함수가 전달 받은 인자를 다른 함수에 보낼때
// => 어떠한 변화도 없이 완벽하게 동일하게 보내는 기술.
// => 아래 함수는 복사본을 만들게 되므로 "완벽한 전달" 아님. 

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
