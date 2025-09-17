#include <vector>

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

	Dog*    p1 = &dog; // ok
//	int*    p2 = &dog; // error

	// 핵심 #1. 기반 클래스 포인터로 파생 클래스 객체의 주소를 담을수 있습니다.
	// => upcasting 이라고 합니다.
	// => 객체지향 프로그래밍 가장 중요한 핵심!!!
	// => 왜 가능한지는 "메모리 그림" 을 그려 보세요
	Animal* p3 = &dog; // ok

	// 핵심 #2. 컴파일러는 p3가 가리키는 곳의 객체가 어떤 타입인지는 알수 없다.
	// => 컴파일러가 아는 것은 p3 자체가 Animal* 라는 것만 알수 잇다.
	// => 아래 같은 코드가 있다면 실행시간에 p3가 가리키는 곳이 변경될수 있으므로 
	// if ( 사용자 입력 == 1 ) p3 = new Animal;


	// 핵심 #3. Animal* 인 p3로는 Animal 로 부터 상속된 멤버만 접근 가능.
	// => Dog 고유의 멤버는 접근할수 없습니다
	// => 이유는 "컴파일 시간에는 p3가 가리키는 객체가 어떤 객체인지 알수 없으므로"
	//    즉, Dog 라는 보장이 없기 때문에, 무조건 안되도록 한다.

	// static type check  : 메모리 접근시 컴파일 시간에 타입 확인 (C++,C#, Java)
	// dynamic type check : 메모리 접근시 실행   시간에 타입 확인 (Python)

	p3->age = 10;   // ok
	p3->color = 10; // error

	
	// 핵심 #4. Animal* 인 p3로 Dog 의 고유 멤버에 접근하려면
	// => 개발자가 Dog* 로 캐스팅해서 사용해야 합니다.
	// => 즉, 개발자가 알려주고 책임져야 합니다.

	static_cast<Dog*>(p3)->color = 10; // ok
				// 단, 이경우 p3가 가리키는 곳이 Dog라는 확신이 있어야 합니다.
				// Dog가 아니라면 잘못된 메모리 참조!!

	
	// 핵심 #5. p3가 가리키는 곳이 Dog 인지 조사할수는 없나요 ??
	// => dynamic_cast 사용하면 됩니다.
	// => 다음 예제에서.. 
}




