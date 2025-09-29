#include <iostream>

class Point
{
public:
	Point() { std::cout << "Point()\n";}
	Point(int, int) { std::cout << "Point(int, int)\n";}

	Point(const Point& obj) {std::cout << "copy\n";}
	Point(Point&&) noexcept {std::cout << "move\n";} // C++11
};

int main()
{
	// 아래 한줄을 완벽히 이해해 봅시다.
	Point pt = Point(0, 0); 

	// C++98
	// 1. 우변이 임시객체를 만들고 - 인자 2개 생성자
	// 2. 복사 생성자로 pt 에 복사
	// => 하지만 대부분 컴파일러가 최적화 하면서, 인자2개 생성자만 한번 호출. 
	// => "copy ellision" 이라는 최적화
	// => -fno-elide-constructors 로 하면 최적화 하지 말라.

	// C++11
	// 1. 우변이 임시객체를 만들고 - 인자 2개 생성자
	// 2. 이동 생성자로 pt 에 복사
	// => 하지만 대부분 컴파일러가 최적화 하면서, 인자2개 생성자만 한번 호출. 
	// => "copy ellision" 이라는 최적화
	// => -fno-elide-constructors 로 하면 최적화 하지 말라.

	// C++17
	// => "copy ellision" 최적화가 문법으로 변했습니다.
	// => -fno-elide-constructors 옵션이 있어도 
	//    인자 2개인 생성자만 호출
	// => "mandantory copy ellision" 이라는 이름. 찾아보세요.. 

}