#include <iostream>
#include <string>
#include <vector>

// setter 만들기

class People
{
private:
	std::string name;
	int age;

public:
	// 최선의 setter 를 만들어 봅시다.
//	void set_name(std::string n) { name = n; } // call by value, bad

	// C++98 시절에는 "best!"
	// C++11 이후는 나쁘지 않지만, 최선 아님. 
	// => move 를 지원하지 못하는 setter, 아래 main 참고
//	void set_name(const std::string& n) { name = n; }  // 항상 복사

	// [참고] 아래 코드도 항상 복사, 인자 n의 const 이므로!!!
//	void set_name(const std::string& n) { name = std::move(n); }

	// 해결책 
	// => setter 가 move를 지원하려면 2개를 만들어야 한다.
	// => 최선의 코드, STL 의 대부분의 멤버함수들, 오픈소스들이 대부분 아래 처럼 구현
	void set_name(const std::string& n) { name = n; }
	void set_name(std::string&& n)      { name = std::move(n); }
};
int main()
{
	std::string s1 = "kim";
	std::string s2 = "lee";

	People p;

	p.set_name(s1);				// 함수 호출뒤에도 s1 사용할예정, 자원을 복사해 가라는 것
	p.set_name(std::move(s2));	// 함수 호출뒤에도 s2 사용안함,   자원을 이동해 가라는 것

	std::cout << s1 << std::endl; // "kim"
	std::cout << s2 << std::endl; // ""
}
// cpprefrence.com 
// std::vector 검색,
// push_back() 멤버 함수 보세요








