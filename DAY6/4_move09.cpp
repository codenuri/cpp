#include <iostream>
#include <vector>

class Object
{
public:
	Object() {}
	Object(const Object&) {	std::cout << "copy" << std::endl;	}	// 복사 생성자
	
	// 이동 생성자 권장
	// => 내부적으로 "예외"가 발생하지 않도록 만드세요
	// => 대부분 포인터나 값 복사이므로 거의 예외 없습니다
	// => 그리고 예외가 없음을 컴파일러에게 알리기 위해서 "noexcept" 를 표기
	Object(Object&&) noexcept
	{
		std::cout << "move" << std::endl;
	}
};

int main()
{	
	Object o1;
	Object o2 = o1; // 무조건 복사 생성자 사용
	Object o3 = std::move(o1); // 무조건 이동 생성자 사용
	Object o4 = std::move_if_noexcept(o2); // 이동생성자에 예외가 없을때만(noexcept가 붙은 경우만)
											// 이동생성자 사용, 
											// noexcept가 없으면 복사 생성자 사용
											// 아래 vector 의 resize 가 이 함수사용. 

	std::vector<Object> v(5);
	std::cout << "----------------" << std::endl;

	v.resize(10); // 원리를 생각해 봅시다.

	std::cout << "----------------" << std::endl;
}

