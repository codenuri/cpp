// 07_정적멤버6.cpp
#include <iostream>


class Date 
{
	int year;
	int month;
	int day;
public:
	Date(int y, int m, int d) : year{y}, month{m}, day{d} {	}
	void set_month(int m) 
	{
		if ( m >= 1 && m <= 12 )
			month = m;
	}
	int get_month() const { return month; }

};

int main()
{
	Date today{2025, 8, 20};

	// Date 타입을 만드는 사람은
	// => 어떤 멤버 함수를 제공해야 사용자들이 편리할까를 생각해야 합니다

	Date d = today.after_days(1000); // 1000 일뒤의 날짜를 알고 싶다.
}