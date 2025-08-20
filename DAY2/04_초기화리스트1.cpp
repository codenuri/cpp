// 6_초기화리스트1    89page ~
#include <iostream>

class Point
{
	int x, y;
public:
	// member initializer list (멤버 초기화 리스트)
	// => 생성자 () 뒤에 : 을 표기하고, 각 멤버를 초기화 하는 것.. 

	Point(int a, int b) : x(a), y(b)  // 좋은 코드!!!
	{
//		x = a;  // 나쁜 코드!!
//		y = b;  // 이렇게 하지 마세요
	}
};

int main()
{
	Point pt(0, 0);
}




