#include <iostream>

// 상속과 생성자 호출의 원리 <= 이번 기회에 완벽히 마스터 하세요. 
// => C#, Java, Swift 는 모든 객체지향 언어의 공통의 특징 

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
	// 사용자 코드		// 컴파일러가 변경한 코드
	Derived()          // Derived() : Base()      <= 컴파일러가 추가
	{ 
		std::cout << "Derived()" << std::endl; 
	} 
	Derived(int a)  	// Derived(int a) : Base() <= 컴파일러가 추가한 코드는 항상
	{ 												// 기반 클래스의 디폴트 생성자 호출
		std::cout << "Derived(int)" << std::endl; 
	}
	~Derived()      
	{ 
		std::cout << "~Derived()" << std::endl; 

		// 소멸자는 자신의 구현을 먼저 실행하고 기반 클래스 소멸자 호출
		// Base::~Base()
	}
};
int main()
{
//	Derived d;		// call Derived::Derived()
	Derived d(5);	// call Derived::Derived(int)
}




