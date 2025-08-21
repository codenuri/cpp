#include <iostream>

// 초급 C++ 개발자가 아주 많이 실수하는 문법
// => 반드시 알아야 합니다.

// 결론 
// C++로 작성된 코드에서 "상속문법을 사용" 한다면
// 기반 클래스 소멸자는 "반드시 가상함수로" 해야 합니다.
// => 너무 중요한 규칙인데, 잘 안지키는 경우가 너무 많습니다.

class Base
{
public:
	Base()  {  }
//	~Base() {  }
	virtual ~Base() {  } // ok
};

class Derived : public Base
{
public:
	Derived()  { std::cout << "Derived() 자원할당" << std::endl; }
	~Derived() { std::cout << "~Derived() 자원해지" << std::endl; }
};

int main()
{
//	Derived d;	// 문제 없음

//	Derived* p = new Derived;	// 문제 없음.
//	delete p; 

	// 아래 코드가 문제!!! 버그!!
	Base* p = new Derived;
	delete p; 
	// 1. delete p 하는 순간 소멸자 호출
	// 2. 소멸자도 함수 이므로 "p->소멸자()"
	// 3. 그런데, 소멸자가 가상함수가 아니므로
	//    "p->소멸자()" static binding 하게 되고
	// 4. static binding 의 원리는 p 의 포인터 타입으로 호출
	// 5. p는 Base* 이므로 
	//    ~Base() 호출. 

}