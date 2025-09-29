#include <iostream>

// shallow copy vs deep copy
// => 아래 코드가 어려우신 분은 "아래 3개 주제"를 먼저 학습하고 move 를 학습해야 합니다.
// => 1. 복사 생성자 
// => 2. 디폴트 복사 생성자의 문제점
// => 3. 얕은 복사와 깊은 복사
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

	// 깊은 복사를 구현한 복사 생성자
	Cat(const Cat& c) : age(c.age)
	{
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);
	}	
};
int main()
{
	Cat c1("nabi", 2);
	Cat c2 = c1; 
}



/*
	Cat(const Cat& c) : age(c.age)
	{
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);
	}
	*/