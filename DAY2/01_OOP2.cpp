#include <iostream>

// 객체 지향 프로그래밍의 핵심
// => 필요한 타입을 먼저 설계한다.

struct Rect 
{
	int left;
	int top;
	int right;
	int bottom;
};



int getRectArea(int left, int top, int right, int bottom)
{
	return (right - left) * (bottom - top);
}

void drawRect(int left, int top, int right, int bottom)
{
	std::cout << "draw rect" << std::endl;
}

int main()
{
	int n1 = getRectArea(1, 1, 10, 10);
	drawRect(1, 1, 10, 10);
}

// github.com/codenuri/cpp 에서 

// DAY2.zip 받으시면 됩니다.
