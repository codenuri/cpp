#include <iostream>

// 핵심 2. 모든 도형의 공통의 기반 클래스가 있다면
// => 색상 등의 공통의 특징을 한곳에 관리할수 있고
// => 모든 도형을 하나의 배열에 보관할수 있다.

class Shape 
{
	int color;
public:
};


class Rect : public Shape 
{
public:
	void draw() { std::cout << "draw Rect\n"; }
};

class Circle : public Shape
{
public:
	void draw() { std::cout << "draw Circle\n"; }
};
int main()
{
//	Rect* arr[10];	// Rect 만 보관 가능하다.
	Shape* arr[10];	// 모든 도형을 보관 가능 
}
