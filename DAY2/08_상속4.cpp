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
	Derived() {}			// Derived()      : Base() {}
	Derived(int a) {}		// Derived(int a) : Base() {}
};

int main()
{
}




