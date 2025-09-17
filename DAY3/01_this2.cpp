#include <iostream>

class Point
{
	int x, y;
public:
	void set(int x, int y) 
	{
		// 멤버 데이타와 함수 인자의 이름 충돌. 
//		x = x;	// 인자 x = 인자 x
//		y = y;

		// 멤버 임을 명확히 하려면 this 사용
		this->x = x;
		this->y = y;
	}
};
int main()
{
	Point p1;
	p1.set(10, 20);
}
