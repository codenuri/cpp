// 5_생성자1.cpp 80page ~
#include <iostream>

class Car
{
private:
	int color;
	int speed;

public:	
/*
	void init(int c, int s)
	{
		color = c;
		speed = s;
	}
*/
	// 생성자
	// 1. 클래스 이름과 동일한 함수
	// 2. 반환값이 없고, 반환 타입도표기하지 않는다.
	// 3. 객체를 생성하면 자동으로 호출된다.
	// 필요성 : private 의 멤버 데이타 초기화를 위해 사용
	Car(int c, int s)
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
	// Car c;
	// c.init(1, 80);

	// #2. 생성자를 사용한 초기화
	Car c(1, 80);

}



