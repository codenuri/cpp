#include <iostream>

class Animal
{
public:
	void cry() { std::cout << "Animal cry" << std::endl; } // 1
};

class Dog : public Animal
{
public:
	// function override : 기반 클래스 멤버 함수를 파생 클래스가 다시 만드는 것 
	void cry() { std::cout << "Dog cry" << std::endl; }  // 2
};

int main()
{
	Animal a; a.cry(); // "1. Animal cry"
	Dog    d; d.cry(); // "2. Dog    cry"

	Animal* p = &d;		

	// p               : Animal*
	// p가 가리키는 객체 : Dog

	// 아래 코드는 어느 함수를 호출할까요 ?
	// => 논리적으로는 Dog cry 가 맞습니다.
	// => 객체가 Dog 이므로
	p->cry();

	// 그런데, 언어마다 동작이 다릅니다.
	// C++/C# : Animal Cry
	// Java, Python, Swift, Kotlin, Objective-C : Dog Cry
}

// 위와 관련된 이론을 정리해 봅시다.

// p->cry() 를 어느 함수로 연결할 것인가 ?
// => 함수 바인딩이라고 합니다.

// 2개의 바인딩이 있습니다.

// 1. static binding



// 2. dynamic binding