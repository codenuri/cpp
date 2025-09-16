#include <iostream>
#include <string>

class People1 
{
	std::string name;
	int age;
public:
	// 아래 코드에서 name 에 값을 넣는 순간을 생각해 봅시다.
	// => 초기화가 아닌 대입니다.
	// => 즉, 2번의 함수 호출로 name에 값을 넣게 됩니다.
	People1(const std::string& n, int a)
	{
		// 1. 컴파일러가 name 의 디폴트 생성자를 호출하는 코드 추가
		// call string::string() <= name 에 대해서

		name = n;	// 2. call name.operator=(n) 의 코드
					// 즉, 대입 연산자 호출. 
		age = a;
	}
};
// 	People1 p1{"kim", 20};






class People2
{
	std::string name;
	int age;
public:
	// 아래 코드는 초기화 리스트를 사용한것!
	People2(const std::string& n, int a) : name{n}, age{a}
	{
		// 컴파일러가 name의 생성자 호출을 아래 처럼 
		// call string::string(n)
		// 즉, 생성자 1회 호출로 초기화 한것!!
		// 대입이 아닌 초기화 입니다.
		// => People1 보다 빠릅니다.
	}
};

int main()
{
	People1 p1{"kim", 20};
	People2 p2{"kim", 20};
}




