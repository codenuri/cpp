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


// 1. static binding  : 컴파일 시간에 컴파일러가 함수를 결정
//						핵심 ) 컴파일러는 p 가 가리키는 객체의 타입은 알수 없다.
//							   컴파일러가 아는 것은 p 자체의 타입이 Animal* 라는 것만 알고 있다
//						따라서, 컴파일러거 결정하면 p자체의 타입으로 결정
//						Animal cry 호출
// 논리적이지 않지만 빠르다.
// C++/C# 의 기본 바인딩

// 2. dynamic binding : 컴파일 시간에는 p 가 가리키는 메모리는 조사하는 기계어 코드 생성
//						실행시간에 "메모리 조사해서" 함수를 결정
//						p가 가리키는 곳에 있는 객체가 Dog 라면 
//						Dog cry 호출
// 논리적이지만 느리다.
// Java, swift, python, kotlin 
// C++/C# 의 virtual function