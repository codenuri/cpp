#include <iostream>
#include <string>
#include <vector>
#include <array>

// 

class People
{
private:
	std::string name;
	std::string address;
public:
	// 인자가 2개인 setter에 move 지원하기.
	/*
	void set(const std::string& n, const std::string& a)
	{
		name = n;
		address = a;
	}
	void set(std::string&& n, const std::string& a)
	{
		name = std::move(n);
		address = a;
	}
	void set(const std::string& n, std::string&& a)
	{
		name = n;
		address = std::move(a);
	}
	void set(std::string&& n, std::string&& a)
	{
		name = std::move(n);
		address = std::move(a);
	}
	*/
	// 결론
	// => 인자가 2개인 setter 가 move 를 지원하려면 "4" 개의 함수를 제공해야 합니다.
	// => 인자가 3개인 setter 가 move 를 지원하려면 "8" 개의 함수를 제공해야 합니다.
	// => 인자가 N개인 setter 가 move 를 지원하려면 "2^N" 개의 함수를 제공해야 합니다.

	// 사실상 불가능합니다.
	// => 다른 방법이 없을까요 ?
	// => forwarding reference 와 완벽한 전달을 알아야 합니다. 
	// => 그래야 해결 가능. 

	// 아래 코드가 해결책
	template<typename T, typename U>
	void set(T&& n, U&& a) 
	{
		name = std::forward<T>(n);
		address = std::forward<U>(a);
	}
};

int main()
{
	std::string name = "kim";
	std::string addr = "seoul";

	People p;
	p.set(name,			   addr);
	p.set(std::move(name), addr);
	p.set(name,			   std::move(addr));
	p.set(std::move(name), std::move(addr));
}








