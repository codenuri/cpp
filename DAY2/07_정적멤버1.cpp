// 3_정적멤버1 - 110 page
#include <iostream>

// Car 객체를 몇개나 생성했는지 갯수를 알고 싶다

class Car
{
	int color;
	int speed;
public:
	int cnt = 0;

	Car()  { ++cnt; }
	~Car() { --cnt; }
};

int main()
{
	Car c1;
	Car c2;

	std::cout << c1.cnt << std::endl;
}

