#include <iostream>


class Car
{
	int color;
	int speed;
public:
	static int cnt;		
	Car()  { ++cnt; }
	~Car() { --cnt; }
};
int Car::cnt = 0;

int main()
{
	std::cout << Car::cnt << std::endl;

	Car c1;
	Car c2;

	std::cout << Car::cnt << std::endl;
}
