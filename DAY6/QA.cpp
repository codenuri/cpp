#include <iostream>

class Point
{
public:
	Point() { std::cout << "Point()\n";}
	Point(int, int) { std::cout << "Point(int, int)\n";}

	Point(const Point& obj) {std::cout << "copy\n";}
//	Point(Point&&) noexcept {std::cout << "move\n";}
};

int main()
{
	// 아래 한줄을 완벽히 이해해 봅시다.
	Point pt = Point(0, 0); 

	// C++98

	// C++11

	// C++17

}