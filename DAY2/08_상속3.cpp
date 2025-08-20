// 상속과 생성자.   135page ~
#include <iostream>

// 생성자 호출원리(순서)를 완벽히 이해해 봅시다.
// => 대부분의 다른 언어도 유사하므로 반드시 알아두세요

class Base
{
public:
	Base()      { std::cout << "Base()"  << std::endl; }
	Base(int a) { std::cout << "Base(int)" << std::endl; }
	~Base()     { std::cout << "~Base()" << std::endl; }
};

class Derived : public Base
{
public:
	// 상속 관계 에서 생성자 호출의 원리

	// 사용자 코드			 // 컴파일러가 변경한 코드
	Derived()      			// Derived() : Base() 
	{ 
		std::cout << "Derived()" << std::endl; 
	} 
	Derived(int a)  		// Derived(int a) : Base()  <<== 핵심 : 컴파일러가 추가한 코드는
	{ 												    //  항상 기반 클래스의 디폴트생성자호출
		std::cout << "Derived(int)" << std::endl; 
	}
	~Derived()      
	{ 
		std::cout << "~Derived()" << std::endl; 

		// 소멸자는 위 구현이 먼저 실행되고..
		// 기반 클래스 소멸자 호출
		// Base::~Base()
	}
};

int main()
{
	Derived d;	
//	Derived d(5);
}




