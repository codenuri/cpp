#include <iostream>
#include <string>

class People
{
	std::string name;
	int age;
public:
	People(const std::string& name, int age) : name{name}, age{age} {}
};
// 아래 코드 작성해 보세요
// 1. People 로 부터 상속받은 Student 를 만들어 보세요
// 2. Student 에 int id 멤버 데이타 추가해 보세요
// 3. Student 에 생성자 추가해 보세요 <===  핵심 
// 4. main 에서 Student 객체 생성해 보세요

class Student : public People 
{
	int id;
public:
	// 아래 처럼 만들면 			   컴파일러가 아래 처럼 변경 
//	Student( int id ) : id{id} {}	// Student( int id ) : People(), id{id} {}

	// 핵심 
	// => Student 만드는 사람은 People 에 디폴트 생성자가 없다는 것을 알고 있어야 합니다
	// => Student 생성자 만들때 People 에 다른 생성자를 명시적으로 호출해야 합니다
	// => 아래 처럼 People 에 생성자에 보낼 name, age 도 생성자인자로 받아서 People 에 전달해야 합니다.
	Student( const std::string& name, int age, int id ) : People{name, age}, id{id} {}
};
int main()
{
	Student s{"kim", 20, 15};
}






