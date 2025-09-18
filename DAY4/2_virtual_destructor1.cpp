#include <iostream>

class Base
{
public:
	Base()  {  }
	~Base() {  }
};
class Derived : public Base
{
public:
	Derived()  { std::cout << "Derived()" << std::endl; }
	~Derived() { std::cout << "~Derived()" << std::endl; }
};

int main()
{
	// 아래 코드는 아무 문제 없음
//	Derived d;	

	// 아래 코드도 아무 문제 없음.
//	Derived* p = new Derived;
//	delete p; 

	// 아래 코드가 문제.!!!
	Base* p = new Derived;
	delete p; 	// 이순간 Derived 소멸자 호출 안됨

	// 소멸자 호출도 결국 함수 호출 입니다.
	// 따라서 "p->소멸자()"

	// 아래 주석을 정확히 이해해 보세요(컴파일러의 원리)
	// 1. p가 Base* 이므로 Base 클래스를 조사해서 
	//    소멸자가 virtual 인지 아닌지 조사 

	// 2. 소멸자가 virtual 이 아니면 : static binding 즉, 포인터타입으로 소멸자 호출
	//    소멸자가 virtual 이면     : dynamic binding 즉, 객체를 조사해서 소멸자 호출


}