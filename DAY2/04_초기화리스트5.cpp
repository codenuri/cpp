#include <iostream>

class Point
{
public:
	int x, y;

	Point() : y(0), x(y)
	{
	}
};
int main()
{
	Point pt;

	std::cout << pt.x << std::endl; // ?
	std::cout << pt.y << std::endl; // ?
}




