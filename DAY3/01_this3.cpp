#include <functional>

class Dialog 
{
public:
	void close(int code) {}
	static void close2(int code) {}
};

void foo(int n) {}

int main()
{	
	// #1. 멤버 함수와 함수 포인터. 
	void(*f1)(int) = &foo;				// ok
//	void(*f2)(int) = &Dialog::close;	// error. 멤버 함수 이므로 this가 추가됩니다.
										//		   즉, 인자가 int 한개 아닙니다.
										//			그래서 안됩니다.
	void(*f3)(int) = &Dialog::close2;	// ok. static 멤버 함수는 this 추가 안됨. 
}