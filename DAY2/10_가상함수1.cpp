// 7_가상함수1  143 page ~
#include <iostream>
// 중요한 문법
// => 예전에는 임베디드 분야에서 사용하지 말라고 했었는데..
// => 요즘은 "정확한 원리를 알고 사용해라" 권장. 

class Animal
{
public:
	void Cry1() { std::cout << "Animal Cry1" << std::endl; } // 1
};

class Dog : public Animal
{
public:
	// 함수 오버라이드(override)
	// => 기반 클래스의 멤버 함수와 동일한 이름의 멤버 함수를 만드는 것
	void Cry1() { std::cout << "Dog Cry1" << std::endl; }  // 2
};

int main()
{
	Animal a; a.Cry1(); // Animal Cry1 호출
	Dog    d; d.Cry1(); // Dog    Cry1 호출

	Animal* p = &d; // 객체는 Dog, 포인터 타입은 Animal 		

	p->Cry1();	// ?? 어떤 함수가 호출될까요 ?
				// 어떤 함수를 호출하는게 논리적으로 맞을까요 ?
				// 여러분이 언어를 설계한다면 어떤 함수가 호출되게 만들까요 ?

	// C++, C# : Animal Cry1 호출

	// Java, Python, Kotlin, Rust : Dog Cry1 호출

}

// p->Cry1() 을 어떤 함수와 연결할것인가 ?
// => 함수 바인딩(binding) 이라고 합니다.
// => 2개의 바인딩이 있습니다.

// static binding : 컴파일 시간에 컴파일러가 함수 호출을 결정
//				    핵심 : 컴파일 시간에는 p가 가리키는 곳에 있는 객체가 어떤 타입인지 알수없다.
//					그래서, 무조건 p 자체의 타입으로 함수 호출을 결정
//					p 는 Animal* 이므로
//					Animal Cry1 호출
// 논리적이지 않지만, 빠르다.
// C++, C# 언어의 기본 바인딩 정책

// dynamic binding : 컴파일 시간에는 p가 가리키는 메모리를 조사하는 기계어 코드 생성
//					 실행시 메모리 조사후 함수 호출 결정
//					 메모리에 Dog 가 있었다면 Dog Cry1 호출
// 논리적이지만 느리다.
// Java, Python, Kotlin, Rust 
// C++, C# 의 가상함수
