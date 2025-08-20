// 4_접근지정자 - 76page~
#include <iostream>

struct Car
{
private:		// private 영역
	int speed;	// 이 영역에 있는 것들은 멤버 함수만 접근 가능하고	
				// 멤버 함수가 아닌 곳에서는 접근 할수 없다.

public:			// public 영역 : 이 영역에 있는 것들은 외부에서 접근 가능
	void set_speed(int s)
	{
		speed = s;
	}
};

int main()
{
	Car c;

//	c.speed = -10; 	// 사용자가 실수 했다. 
					// private 영역에 있었다면 컴파일 에러. 

	c.set_speed(-10);			 
}
