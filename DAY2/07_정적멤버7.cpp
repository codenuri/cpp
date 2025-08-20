// 07_정적멤버6.cpp
#include <iostream>


class Date 
{
	int year;
	int month;
	int day;

	// 월별 날짜수 관리
	// => 핵심 : 아래 멤버 데이타가 static 인 이유를 명확히 알아야 합니다.
	// => 문법상. static 멤버 데이타(배열) 초기화는 클래스 외부에서 
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
		Date tmp{year, month, day + ds}; // 잘못된 구현
										// 복습할때 제대로 구현해 보세요
										// days[] 배열 참고해서

		return tmp;
	}
};

// 복습할때 아래 배열 12개 데이타 제대로 수정해 보세요. 
int Date::days[12] = { 31, 28, 30, 31, 30, 31, 30, 31, 31, 30, 30, 31 }; 

int main()
{
	Date today{2025, 8, 20};

	// Date 타입을 만드는 사람은
	// => 어떤 멤버 함수를 제공해야 사용자들이 편리할까를 생각해야 합니다

	Date d = today.after_days(1000); // 1000 일뒤의 날짜를 알고 싶다.
}