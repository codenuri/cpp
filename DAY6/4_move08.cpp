#include <iostream>
#include <string>

// rule of 0
// => 자원을 직접 관리하지 않고, 자원 관리 클래스를 사용해라
// char* => std::string
// int* => vector 또는 스마트 포인터

// 아래 코드는 
// => 복사 생성자, 이동생성자, 대입 연산자, 복사 대입연산자를 모두 지원하는 완벽한 코드
// => 아무 것도 만들지 않은 것이 최선의 코드이다.
class Cat
{
	std::string name;
	int   age;
public:
	Cat(const std::string& n, int a) : name{n}, age{a}
	{
	}
};


int main()
{
	Cat c1("nabi", 2);
	
	Cat c2 = c1;   	
	c2 = c1;		

	Cat c3 = std::move(c1);	
	c3 = std::move(c2);		

}




