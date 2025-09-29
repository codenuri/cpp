#include <iostream>

// 아래 코드가 move 의 핵심
// => 정확히 이해 하세요

class Cat
{
	char* name;
	int   age;
public:
	Cat(const char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n)+1, n);
	}
	~Cat() { delete[] name; }

	// 일반적인 복사 생성자
	// => "깊은 복사로 구현"
	Cat(const Cat& c) : age(c.age)
	{
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);
	}

	// temporary 를 위한 복사 생성자
	// => 인자로 Cat&& 사용
	// => 이동(move) 기술.
	Cat(Cat&& c) : name{c.name}, age{c.age}
	{
		// temporary 가 자원을 delete 할수 없도록
		// 자원 포인터를 reset
		// => 아래 코드를 실행하려면 "상수성 없이 temporary를 가리킬수 있어야 했다."
		// => 그래서 rvalue reference 는 상수성 없이 temporary 가리키는 것이 가능. 
		c.name = nullptr;
	}	
};

// #1. foo() 의 값환 값은 "temporary" 입니다.
Cat foo()
{
	Cat c{"yaong", 3};
	return c;
}

int main()
{
	Cat c1("nabi", 2);
	Cat c2 = c1; 

	Cat c3 = foo(); // 이 순간의 메모리 상태를 이해 해야 합니다.
}
