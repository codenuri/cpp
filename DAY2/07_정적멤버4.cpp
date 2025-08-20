#include <iostream>


class Car
{
	int color;
	int speed;

	static int cnt;			
public:

	Car()  { ++cnt; }
	~Car() { --cnt; }

	// 아래 처럼 만들면 "객체가 있어야 호출 가능" 합니다.
	// => c1.get_count() 로 사용해야 하므로 c1 이 필요
//	int get_count() const { return cnt; }

	// static 멤버 함수
	// => 객체가 없어도 호출가능한 함수
	// => "Car::get_count()" 로 호출
	// => 객체 자체가 없이 호출 하므로 const 함수라는 개념자체가 없음. 
	static int get_count() { return cnt; }
};
int Car::cnt = 0;

int main()
{
	std::cout << Car::get_count() << std::endl;

	Car c1;
	Car c2;

	std::cout << Car::get_count() << std::endl;
}

// static 멤버 데이타
// => 모든 객체가 공유하는 멤버 데이타
// => 전역변수와 유사
// => "Car 만 사용하는 전역변수" 라는 의미 - private 보호가능.

// static 멤버 함수
// => 객체 없이 클래스 이름으로만 호출하는 멤버 함수
// => "클래스이름::함수이름()" 으로 호출

// 위 개념은 거의 모든 객체지향 언어에서 제공하는 개념
// => 반드시 정확한 개념이해해 두세요.. 