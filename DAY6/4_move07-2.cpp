#include <iostream>
#include <string>

// 규칙 #3. 사용자가 이동 계열만 제공할때
// => 컴파일러는 복사 계열 제공 안함

// 복사생성자가 필요한 코드가 있다면
// => 컴파일 에러

struct Object
{
	std::string name;
	Object(const std::string& n) : name(n) {}	

	Object(Object&& obj) : name{std::move(obj.name)} { std::cout << "user move\n";}

	// 이때 컴파일러에게 복사생성자의 디폴트 버전을 요청하려면 = default 문법 사용
	Object(const Object&) = default;

	// 대입 2개도 모두 디폴트 요청하는 것이 관례
	Object& operator=(const Object&) = default;
	Object& operator=(Object&&) = default;
};

int main()
{
	Object o1{"obj1"};
	Object o2{"obj2"};

	Object o3 = o1;				// error. 	단, =default로 요청했다면 ok 
	Object o4 = std::move(o1);	// "사용자가 만든 move 생성자 호출"
								

	std::cout << o1.name << std::endl; 
	std::cout << o2.name << std::endl; 
}