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








