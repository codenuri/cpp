// 5_상속1.cpp   133page ~
#include <iostream>

class Person
{
	char name[32];
	int  age;
};
// Person 을 확장해서 새로운 타입을 설계 합니다.
// => 상속 문법
// Person  : Base 클래스
// Student : Derived 클래스 라는 용어 사용
class Student : public Person
{	
	int    id;
};

class Professor: public Person
{
	int    major;
};

int main()
{
	Student s;
	Professor p;
}
