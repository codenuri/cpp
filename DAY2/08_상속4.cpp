#include <iostream>

// 아래 코드에서 에러를 모두 찾아 보세요
// => 핵심 : 기반 클래스인 Base 에 디폴트 생성자가 없습니다
class Base
{
public:
	Base(int a) {}
	~Base()     {}
};

class Derived : public Base
{
public:
	// 사용자 코드			 // 컴파일러가 변경한 코드
//	Derived() {}			// Derived()      : Base() {}
//	Derived(int a) {}		// Derived(int a) : Base() {}


	// 해결책 
	// 기반 클래스에 디폴트 생성자가 없다면
	// 파생 클래스 생성자에서 반드시 기반 클래스의 다른 생성자를 호출하는 코드를 제공해야 합니다.
	Derived()      : Base(0) {}
	Derived(int a) : Base(a) {}
};

int main()
{
}




