
#include <iostream>


class Date 
{
	int year;
	int month;
	int day;

	static int days[12];


public:
	Date(int y, int m, int d) : year{y}, month{m}, day{d} {	}
	void set_month(int m) 
	{
		if ( m >= 1 && m <= 12 )
			month = m;
	}
	int get_month() const { return month; }

	Date after_days(int ds) const 
	{
		Date tmp{year, month, day + ds}; 

		return tmp;
	}
};
int Date::days[12] = { 31, 28, 30, 31, 30, 31, 30, 31, 31, 30, 30, 31 }; 

int main()
{
	Date today{2025, 8, 20};

	// 5월달이 몇일까지 있는지 알려주는 함수는 만들고 싶다.
	// =>아래 2개중 어떻게 제공하는 것이 좋을까 ?
	// => 2번이 더 좋은 방식

	// 방법 1. 5월 날짜 객체를 만들고 멤버 함수호출
	Date d1{2025, 5, 1};
	int n1 = d1.how_many_days();

	// 방법 2. 객체없이도 호출가능하게 하자.
	int n2 = Date::how_many_days(5); 


	// 내일 날짜를 알고 싶다 !
	// => "내일" 이라는 개념은 "기준일"이 필요 하다.
	// => 기준이 되는 객체를 만들고 함수 호출
	// => 멤버 함수로 구현. 
	Date t{2025, 8, 20}; 
	Date d2 = t.tomorrow();
}
// 복습하실때 위 how_many_days(), tomorrow() 구현해 보세요
// how_many_days() : static 으로  
// tomorrow()      : non-static 으로 