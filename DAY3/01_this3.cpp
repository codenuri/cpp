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
	// => 일반 함수 포인터에 "멤버함수의 주소" 를 담을수 없다.
	// => 일반 함수 포인터에 "static 멤버함수의 주소" 를 담을수 있다.
	void(*f1)(int) = &foo;				// ok
//	void(*f2)(int) = &Dialog::close;	// error. 멤버 함수 이므로 this가 추가됩니다.
										//		   즉, 인자가 int 한개 아닙니다.
										//			그래서 안됩니다.
	void(*f3)(int) = &Dialog::close2;	// ok. static 멤버 함수는 this 추가 안됨. 


	// #2. 멤버 함수의 주소를 담는 포인터
	// => "멤버 함수 포인터" 라고 하는 문법입니다. - 자주 사용되므로 알아두세요
	void(Dialog::*f2)(int) = &Dialog::close; // ok 

	// #3. 멤버 함수 포인터 사용하기.
	f1(10); // ok. foo(10);

//	f2(10); // ?? 될까요 ? error. 
			// close()는 멤버함수이므로 호출하려면 객체가 필요합니다.
			// dlg.close() 처럼!!
			// 그런데, 이코드는 객체가 없습니다.

	Dialog dlg;
//	dlg.f2(10); // error. dlg 안에 f2 라는 멤버함수는 없습니다.
				// f2 는 멤버 함수가 아닌 멤버 함수 포인터

	// 이때 사용하는 연산자가 .* 라는 연산자 입니다. pointer to member operator
	// => ".*" 자체가 하나의 연산자입니다.
//	dlg.*f2(10); 	// error. 연산자 우선순위 문제.. 

	(dlg.*f2)(10);  // ok. ( 보다 .* 를 우선순위를 높게 한것!!
					// 이코드가 "멤버 함수 포인터로 멤버 함수를 호출하는 코드"
					// => C++중급(특히 게임쪽에서)에서 많이 볼수 있는 코드
	
	// #4. 일반화
	// => 문제점 : 일반함수 포인터와 멤버 함수 포인터를 사용해서 함수 호출하는 방법이
	//				다릅니다
	f1(10); 		// 일반 함수 포인터
	(dlg.*f2)(10); 	// 멤버 함수 포인터

	// 해결책 : C++17 에서 도입된 std::invoke()
	// => <functional> 헤더 필요
	std::invoke(f1, 10);  		// f1(10)
	std::invoke(f2, &dlg, 10);	// (dlg.*f2)(10);

	// 위 코드는 결국 사용법이 동일해 졌습니다.
	// std::invoke()는 아주 널리 사용됩니다. 꼭 기억하세요
}