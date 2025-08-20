#include <iostream>

class Point
{
	int x, y;
public:
	// this 활용 #1. 멤버 임을 명확하기 할때 사용
	void set(int x, int y) 
	{
		this->x = x;	
		this->y = y;
	}
	// this 활용 #2. this 를 반환하면 멤버함수를 연속적으로 호출가능
	//  => method chaining 이라는 기술
	Point* foo() { return this; }
	Point& goo() { return *this; }

};
int main()
{
	Point p1;
	p1.set(10, 20);

	p1.foo()->foo()->foo();
	p1.goo().goo().goo();
}
