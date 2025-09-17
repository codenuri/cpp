#include <iostream>
#include <string>

// 사람의 공통의 특징을 담은 클래스를 먼저 설계하고
class People 
{
	std::string name;
	int age;
};

// People 을 확장해서 새로운 타입을 설계 합니다.
class Student : public People
{	
	int    id;
};
class Professor: public People
{
	int    major;
};

int main()
{
	Student s;
	Professor p;
}
