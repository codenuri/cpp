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
