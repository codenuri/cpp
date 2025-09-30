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
	// 방법 #1.
	void set_name(const std::string& n) { name = n; }
	void set_name(std::string&& n)      { name = std::move(n); }

	// T&& 를 사용하면 위 "방법#1" 을 자동생성 가능
	// => 그런데, 인자가 한개인 set_name()은 위 처럼 2개 만드는 것 권장
	template<typename T>
	void set_name(T&& n)
	{
		// 다음중 맞는 것은 ?
//		name = n;				// 항상 복사
//		name = std::move(n);	// 항상 move
		name = std::forward<T>(n);	// 인자로 전달시 lvalue 를 보내면 copy
									//			    rvalue 를 보내면 move
									// 정답
	}
};

int main()
{
	std::string s1 = "kim";
	std::string s2 = "lee";

	People p;

	p.set_name(s1);				
	p.set_name(std::move(s2));	

	std::cout << s1 << std::endl; // "kim"
	std::cout << s2 << std::endl; // ""
}








