// 3_정적멤버1 - 110 page
#include <iostream>

// 방법 #3. 



class Car
{
	int color;
	int speed;
public:
//	int cnt = 0;		// 멤버 데이타 : 객체당 한개씩 생성

	static int cnt;		// static 멤버 데이타 : 오직 한개만 생성, 모든 객체가 공유


	Car()  { ++cnt; }
	~Car() { --cnt; }
};

// static 멤버 데이타는 반드시 클래스 외부 선언 필요합니다.
// => 초기화도 이 위치 에서.. 
int Car::cnt = 0;



int main()
{
	Car c1;
	Car c2;

	std::cout << Car::cnt << std::endl;
}

