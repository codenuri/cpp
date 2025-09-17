#include <iostream>
#include <sstream> // std::ostringstream
#include <string>

class Point
{
	int x, y;
public:
	Point(int a, int b) : x{a}, y{b} {}

	// x, y 의 값을 문자열로 반환하는 멤버 함수
	// => const Point p{1,2} 라도 to_string() 호출이 가능해야 하므로 "상수 멤버함수!"
	// => 즉, 멤버 함수 만들때 "const member function" 으로 할지/말지 를 잘 선택하세요
	std::string to_string() const 
	{
		std::ostringstream oss;
		oss << "Point{x=" << x << ", y=" << y << "}";
		std::string s = oss.str();
		return s;
	}	
};
int main() 
{
//	Point p{1, 2};
	const Point p{1, 2};
	
	std::cout << p.to_string() << std::endl;
	std::cout << p.to_string() << std::endl;
}
