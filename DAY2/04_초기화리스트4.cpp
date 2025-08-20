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
	Rect()
	{
		// 이 위치에 컴파일러가 멤버 데이타의 생성자를 호출하는 코드를 추가
		// => 현재 코드를 godbolt.org 에 넣어서 확인해 보세요
		// call Point::Point()  <== leftTop     에 대해서
		// call Point::Point()  <== rightBottom 에 대해서

		std::cout << "Rect()" << std::endl;
	}
};

int main()
{
	Rect r; 
}





