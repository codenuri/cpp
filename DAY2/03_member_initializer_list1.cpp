#include <iostream>
#include <string>

class People 
{
	std::string name;
	int age;
public:
	// member intializer list
	// => 생성자 ()뒤에 : 을 표기하고 멤버 데이타를 초기화 하는 것
	// => C++11 이후는 () 보다 {} 권장
//	People(const std::string& n, int a) : name(n), age(a) // 좋은 코드
	People(const std::string& n, int a) : name{n}, age{a} // 좋은 코드
	{
		// 아래 처럼 멤버를 초기화 하는 것은 "나쁜 코드"
		// name = n;	// bad
		// age = a;
	}
};

int main()
{
//	People p("kim", 20); // 예전 스타일
	People p{"kim", 20}; // C++11 이후 권장
}




