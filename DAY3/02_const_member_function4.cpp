#include <iostream>
#include <sstream> // std::ostringstream
#include <string>

class Point
{
	int x, y;

	// mutable 
	// => 상수 멤버 함수 에서도 값을 변경할수 있게 해달라는 의미
	// => to_string() 은 논리적으로는 상수 멤버함수가 되는게 맞지만
	//    다양한 테크닉을 위해서는 멤버의 값을 변경할 필요가 있다.
	//    (논리적 상수성 이라는 문제)

	// => 상수 멤버 함수를 사용하기 시작하면 많은 에러가 발생할수있습니다.
	//    적절한 문법과 다양한 테크닉으로 해결해야 합니다.
	mutable std::string cache;
	mutable bool cache_valid = false;
public:
	Point(int a, int b) : x{a}, y{b} {}

	std::string to_string() const 
	{
		if ( cache_valid == false )
		{
			std::ostringstream oss;
			oss << "Point{x=" << x << ", y=" << y << "}";
			cache = oss.str();

			cache_valid = true;
		}
		return cache;
	}	
};
int main() 
{
	Point p{1, 2};
//	const Point p{1, 2};
	
	std::cout << p.to_string() << std::endl;
	std::cout << p.to_string() << std::endl;
}
