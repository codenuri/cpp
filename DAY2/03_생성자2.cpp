#include <iostream>

class Car
{
private:
	int color;
	int speed;

public:	
	// 핵심 #1. 생성자는 여러개 만들수 있습니다.
	Car() 
	{
		std::cout << "Car()\n";
		color = 0;
		speed = 0;
	}

	Car(int c, int s)
	{
		std::cout << "Car(int, int)\n";
		color = c;
		speed = s;
	}	
};

int main()
{

	Car c(1, 80);

}



