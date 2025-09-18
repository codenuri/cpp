#include <iostream>

// 가상 소멸자 문제는
// 1. Derived 의 소멸자에서 하는 일이 있고
// 2. 아래와 같은 코드가 있을때만 문제가 됩니다.
//	Base* p = new Derived;
//	delete p; 	

// Derived 소멸자에서 하는 일이 없는 경우는 문제가 되지 않습니다
// 그리고, 가상 소멸자를 사용하면 가상함수의 오버헤드가 추가됩니다.

class Base
{
public:
	Base()  {  }

	// protected 소멸자!
	// => Base* 타입으로는 절대 delete 하지 말라는 의미
	// => delete 하는 경우 컴파일 에러. 
protected:
	~Base() {  } 
};
class Derived : public Base
{
public:
	Derived()  { std::cout << "Derived()" << std::endl; }
	~Derived() { std::cout << "~Derived()" << std::endl; } // ~Base()
};
int main()
{
	Base* p = new Derived;
//	delete p; 	// 컴파일에러!

	delete static_cast<Derived*>(p);
}
// 핵심
// 1. 기반 클래스는 "소멸자를 가상함수"로해야 합니다.
// 2. 그런데, 간단한 기반 클래스를 만들때는 "가상함수의 오버헤드가 싫을 때가 있습니다"
// => 이럴때는 기반 클래스 소멸자는 protected 에 놓으세요
// => 아래 같은 코드를 사용하지 못하게 하는 의미 입니다.
//	Base* p = new Derived;
//	delete p;  <== 컴파일 에러. 

// static_cast를 하는 과정에서 발생하는 오버헤드는 없나요?
// => static_cast 는 컴파일러에게 Base* 가 아닌 Derived* 로해석해 달라는 요청
// => 즉, 기계어 코드는 없습니다. 컴파일러에게 단지 요청하는 것
// => 실행시 오버헤드는 0 입니다.


// 구글에서 "C++ core guideline" 검색 
// 1번째 링크 선택
