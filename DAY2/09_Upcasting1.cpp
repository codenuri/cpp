// 6_Upcasting1.cpp      139 page ~
#include <vector>

// upcasting
// => 객체지향 디자인의 핵심
// => C++로 규모있는 프로그램을 개발한다면 반드시 사용하게 되는 핵심 개념. 

class Animal
{
public:	
	int age;
};
class Dog : public Animal
{
public:	
	int color;
};
int main()
{
	Dog     dog;

	Dog*    p1 = &dog; // ok. 당연한 코드
//	int*    p2 = &dog; // error

	// 핵심 #1. 기반 클래스 타입 포인터로 파생 클래스 객체 주소를 담을수 있다.
	// => Upcasting 이라고 합니다.
	// => 가리킬수 있는 이유는 "메모리 그림" 을 생각하세요
	Animal* p3 = &dog; // ok


	// 핵심 #2. 컴파일 시간에는 p3가 가리키는 곳이 실제로 어떤 타입의 객체가 있는지 
	//         알수 없습니다.
	// => 컴파일 시간에는 p3 자체의 타입이 Animal* 라는 것만 알수 있습니다.
	// => 아래 코드를 생각해 보세요
	// Animal a;
	// if (사용자 입력 == 1) p3 = &a;  // 실행시간 변경될수 있다.

	// 핵심 #3. Animal* 인 p3로는 Animal 고유의 멤버만 접근 가능합니다.
	// => 실제 메모리에 Dog 객체가 있어도 Dog 멤버는 접근 할수 없습니다.
	
	p->age = 10;  // ok
	p->color = 20; // error
}




