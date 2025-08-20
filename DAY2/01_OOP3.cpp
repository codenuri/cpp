#include <iostream>

// C 언어도 struct 로 타입을 만들수 있는데 왜, C++ 이 필요 한가요 ?

// C   struct : 함수를 포함할수 없다.
// C++ struct : 함수를 포함할수 있다.

// 타입을 만들때
// => 상태를 나타내는 데이타와 상태를 가지고 연산을 하는 함수를 묶어서 설계 한다.
struct Rect 
{
	// 멤버 데이타
	int left;
	int top;
	int right;
	int bottom;
	// 멤버 함수 - 멤버 함수 안에서는 멤버 데이타를 직접 접근 가능
	int getRectArea()  { return (right - left) * (bottom - top); }
	void drawRect()    { std::cout << "draw rect" << std::endl; }
};

int main()
{
	Rect rc = { 1, 1, 10, 10};
	int n1 = rc.getRectArea();
	rc.drawRect();

//	int n1 = getRectArea(rc);
//	drawRect(rc);
}
