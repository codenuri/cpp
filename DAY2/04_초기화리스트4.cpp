#include <iostream>

class Point
{
	int x, y;
public:
	Point()				: x(0), y(0) { std::cout << "Point()" << std::endl; }
	Point(int a, int b) : x(a), y(b) { std::cout << "Point(int, int)" << std::endl; }
};

class Rect
{
	Point leftTop;
	Point rightBottom;
public:
/*
	Rect()
	{
		// 이 위치에 컴파일러가 멤버 데이타의 생성자를 호출하는 코드를 추가
		// => 현재 코드를 godbolt.org 에 넣어서 확인해 보세요
		// call Point::Point()  <== leftTop     에 대해서
		// call Point::Point()  <== rightBottom 에 대해서
		std::cout << "Rect()" << std::endl;
	}
*/

	// 멤버 데이타의 디폴트 생성자가 아닌 다른 생성자가 호출되게 하려면
	// => 초기화 리스트에서 표기하면 됩니다.
//	Rect(int x1, int y1, int x2, int y2) : leftTop(x1, y1), rightBottom(x2, y2)
	Rect(int x1, int y1, int x2, int y2) : leftTop{x1, y1}, rightBottom{x2, y2}
	{
		// call Point::Point(1, 1)  <== leftTop     에 대해서
		// call Point::Point(2, 2)  <== rightBottom 에 대해서
		std::cout << "Rect()" << std::endl;
	}

};

int main()
{
	Rect r{1, 1, 10, 10}; 
}





