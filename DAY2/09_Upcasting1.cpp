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

	// => 이유는 컴파일러는 p3가 가리키는 곳이 Dog 인지 아닌지 알수 없으므로
	//    안전하게 사용하기 위해 무조건 Animal 멤버만 가능하게
	// => C++ 은 "static type check" 언어 이기 때문에

	// static type check : 타입이 맞는지를 "컴파일 시간"에 확인 - C++, Java, C#, Rust등
	// dynamic type check : 타입이 맞는지를 "실행 시간"에 확인  - 파이썬
	
	p3->age = 10;  // ok
//	p3->color = 20; // error

	// 핵심 #4. Animal* 인 p3 를 사용해서 Dog 고유 멤버에 접근하려면
	// => 캐스팅해서 사용해야 합니다.

	(static_cast<Dog*>(p3))->color = 10; // ok
					// 단, 이경우 p3가 가리키는 곳이 Dog 라는 확신이 있어야 합니다.
					// Dog 가 아니 었다면 잘못된 코드. 실행시간 오류 가능성 있음. 
}




