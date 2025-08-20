#include <iostream>

class Point
{
	int x, y;
	const int c;  // 상수는 반드시 초기화 되어야 합니다.
public:
	Point(int a, int b) : x(a), y(b), c(0)     // <= 이위치는 초기화 입니다.
	{
		// 아래 2줄은 대입니다.
		// x = a; 
		// y = b; 
	//	c = 0; // error. 이 위치는 대입 입니다.
	}
};

int main()
{
	Point pt(0, 0);
}




