// 3_정적멤버1 - 110 page
#include <iostream>

// Car 객체를 몇개나 생성했는지 갯수를 알고 싶다

// 방법 #1. 멤버 데이타 cnt 사용
// => 모든 객체가 각각 자신의 cnt 사용
// => 객체 갯수 파악 실패. 

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

