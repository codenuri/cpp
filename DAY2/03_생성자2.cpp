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

	// #2. 소멸자 개념
	// => ~클래스이름() 의 함수
	// => 인자와 반환 타입이 모두 없어야 한다.
	// => 오직 한개만 만들수 있다.
	// => 객체가 파괴될때 호출
	~Car()
	{
		std::cout << "~Car()\n";
		// 생성자에서 할당한 자원(파일, 소켓등)이 있다면 여기서 해지.
	}
};

int main()
{
	Car c1;  		// 인자 없는 생성자
	Car c2(1, 80);  // 인자 있는 생성자

} // <= c1, c2 파괴. 소멸자 호출



