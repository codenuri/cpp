#include <iostream>
#include <sstream> // std::ostringstream
#include <string>

class Point
{
	int x, y;

	std::string cache;
	bool cache_valid = false;
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
