// 5_생성자1.cpp 80page ~
#include <iostream>

class Car
{
private:
	int color;
	int speed;

public:	
	void init(int c, int s)
	{
		color = c;
		speed = s;
	}
};

int main()
{
	// 아래 처럼 객체를 만들면서 초기화 하는 것은
	// => 모든 멤버가 public 일때만 가능
	// => private 멤버가 있다면 안됨.
	// Car c = { 10, 80};

	// #1. 객체를 생성후, 멤버 함수를 사용해서 초기화
	Car c;
	c.init();

}



