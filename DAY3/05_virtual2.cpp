#include <iostream>

class Animal
{
public:
	// non-virtual : 기본 바인딩인 static binding 해달라는 것
	// => 즉, 호출시 컴파일시간 포인터 타입으로 결정해 달라.
	// => 호출시 오버헤드 없다. 빠르다.
	void cry1() { std::cout << "Animal cry1" << std::endl; }
	
	// virtual : dynamic binding 해달라는 지시어
	// => 즉, 호출시 실행시간에 메모리를 조사한후 실제 객체에 따라 호출해 달라.
	// => 약간의 오버헤드가 있다. cry1 보다 느리다.
	virtual void cry2() { std::cout << "Animal cry2" << std::endl; } 
};

class Dog : public Animal
{
public:
	void cry1() { std::cout << "Dog cry1" << std::endl; }  
	virtual void cry2() { std::cout << "Dog cry2" << std::endl; }  
};

int main()
{
	Dog    d; 

	Animal* p = &d;		

	p->cry1();	// static binding. Animal cry1
	p->cry2();	// dynamic binding.   Dog cry2
}

