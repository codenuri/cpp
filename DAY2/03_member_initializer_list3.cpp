#include <iostream>
#include <string>

class People1 
{
	std::string name;
	int age;
public:
	People1(const std::string& n, int a)
	{
		name = n;
		age = a;
	}
};

class People2
{
	std::string name;
	int age;
public:
	People2(const std::string& n, int a) : name{n}, age{a}
	{
	}
};

int main()
{
	People1 p1{"kim", 20};
	People2 p2{"kim", 20};
}




