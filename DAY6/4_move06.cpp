#include <iostream>

// rule of 5, 3

// 클래스 내부에 포인터가 있고 생성자에서 자원을 할당하는 코드가 있다면

// C++98 : Rule of 3
// => 소멸자, 복사 생성자, 대입연산자

// C++11 이후 : Rule of 5
// => 위 3개 + 이동 생성자, 이동 대입연산자

class Cat
{
	char* name;
	int   age;
public:
	Cat(const char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
	~Cat() { delete[] name; }

	Cat(const Cat& c) : age(c.age)
	{
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);
		std::cout << "COPY" << std::endl;
	}
	
	Cat(Cat&& c): age(c.age), name(c.name)
	{
		c.name = nullptr;
		std::cout << "MOVE" << std::endl;
	}

	// 대입연산자
	Cat& operator=(const Cat& other)
	{
		if ( &other == this) return *this;

		delete[] name;
		age = other.age;
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);

		return *this;
	}
	Cat& operator=(Cat&& other)
	{
		if ( &other == this) return *this;

		delete[] name;
		age = other.age;

		name = other.name;
		other.name = nullptr;
		
		return *this;
	}	
};

int main()
{
	Cat c1("nabi", 2);
	
	Cat c2 = c1;   	// 초기화. 복사 생성자
	c2 = c1;		// 대입,   대입 연산자

	Cat c3 = std::move(c1);	// 초기화, 이동 생성자
	c3 = std::move(c2);		// 대입,   이동 대입연산자

}




