#include <iostream>
#include <vector>

class Object
{
public:
	Object() {}
	Object(const Object&) 	   { std::cout << "copy" << std::endl; }
	Object(Object&&) noexcept  { std::cout << "move" << std::endl; }
};
int main()
{
	const Object o1; // 핵심 : 상수 객체 입니다.
					 // => 상수 객체는 move 될수 없습니다.

	Object o2 = std::move(o1); // move 가 아닌 copy, 복사 생성자 호출	
				// static_cast<o1타입&&>(o1);
				// static_cast<const Object&&>(o1);
				// => 상수 rvalue 이므로 
				// 		=> Object(Object&&)에는 전달 안됨
				//		=> Object(const Object&)에는 전달 가능. 


}

