#include <iostream>
#include <string>

// 규칙 #2. 사용자가 복사 계열만 제공할때 
// => 컴파일러는 "이동계열" 함수를 모두 제공안함

// 이동이 필요한 코드가 있으면
// => 복사를 사용하게 된다.

struct Object
{
	std::string name;
	Object(const std::string& n) : name(n) {}	

	Object(const Object& obj) : name{obj.name} { std::cout << "user copy\n";}
};

int main()
{
	Object o1{"obj1"};
	Object o2{"obj2"};

	Object o3 = o1;				// "사용자가 만든 복사 생성자" 호출
	Object o4 = std::move(o1);	// "사용자가 만든 복사 생성자" 호출
								// => std::move 는 rvalue 로 캐스팅
								// => move 생성자가 있으면 호출, 없으면 복사 사용가능
								// => const & 는 lvalue, rvalue 모두 받을수 있다.

	std::cout << o1.name << std::endl; //"obj1"
	std::cout << o2.name << std::endl; // ""
}