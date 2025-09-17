#include <iostream>

// 아래 코드에서 에러를 모두 찾아 보세요
class Base
{
public:
	Base(int a) { std::cout << "Base(int)" << std::endl; }
	~Base() { std::cout << "~Base()" << std::endl; }
};

class Derived : public Base
{
public:
	// 핵심 #1. 기반 클래스 디폴트 생성자가 없다면 파생 클래스 생성자를 아래 처럼 만들면
	//          에러 입니다.
	//			컴파일러가 변경한 코드 때문에..
	// 사용자 코드			 // 컴파일러가 변경한 코드
//	Derived()     {}		// Derived()      : Base() {}
//	Derived(int a){}		// Derived(int a) : Base() {}

	// 해결책 : 사용자가 기반 클래스의 다른 생성자를 직접 호출해야 합니다
	Derived()     : Base(0) {}
	Derived(int a): Base(a) {}

};

int main()
{
}




