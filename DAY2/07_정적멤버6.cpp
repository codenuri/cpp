// 07_정적멤버6.cpp
#include <iostream>

// 예제!

// 프로그램에서 날짜를 많이 사용한다.
// => "Date" 라는 타입을 만들자

class Date 
{
	int year;
	int month;
	int day;
public:
	Date(int y, int m, int d) : year{y}, month{m}, day{d} 
	{		
	}
	// getter/setter - 관례적인 코드
	// 핵심 : getter 는 상수 멤버 함수이어야 한다.
	void set_month(int m) 
	{
		if ( m >= 1 && m <= 12 )
			month = m;
	}
	int get_month() const { return month; }

	// year,day 의 setter/getter는  복습하실때 구현해 보세요.. 
};

int main()
{
	Date today{2025, 8, 20};

	auto m = today.get_month();
}