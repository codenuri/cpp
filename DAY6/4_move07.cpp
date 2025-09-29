#include <iostream>
#include <string>

// 자동 생성 규칙 - 중요합니다. 잘정리해 두세요
// 
// 규칙 #1. 사용자가 복사 계열(복사 생성자, 대입연산자), 이동 계열(이동생성자, 이동대입연산자)를
//         모두 제공하지 않으면
// => 컴파일러가 모두 제공
// => 컴파일러 제공 복사 생성자 : 모든 멤버 데이타를 복사로 이동
// => 컴파일러 제공 이동 생성자 : 모든 멤버 데이타를 이동
struct Object
{
	std::string name;
	Object(const std::string& n) : name(n) {}	// 일반 생성자

	// 아래 코드가 컴파일러가 만드는 코드
//	Object(const Object& obj) : name{obj.name} {}
//	Object(Object&& obj) noexcept : name{std::move(obj.name)} {}

	// = 도 마찬가지로 2개 버전 모두 제공
};

int main()
{
	Object o1{"obj1"};
	Object o2{"obj2"};

	Object o3 = o1;				// name 이 복사
	Object o4 = std::move(o1);	// name 이 이동
	std::cout << o1.name << std::endl; //"obj1"
	std::cout << o2.name << std::endl; // ""
}