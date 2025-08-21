#include <iostream>

// 1. 모든 파생클래스(도형)의 공통의 특징은 기반 클래스에도 있어야 한다.
// => 문법적인 규칙이 아니라 디자인적인 규칙
// => 그래야, 기반 클래스 포인터로 해당 특징 사용가능.

// 2. 기반 클래스 함수중 파생 클래스가 재정의 하게 된다면
//    반드시 가상함수로 만들어야 한다.
//    그래야, 기반 클래스 포인터로 호출시
//    파생 클래스 함수 호출

class Shape 
{
	int color;
public:
	virtual void draw() { std::cout << "draw Shape\n"; }
};

class Rect : public Shape 
{
public:
	virtual void draw() { std::cout << "draw Rect\n"; }
};

class Circle : public Shape
{
public:
	virtual void draw() { std::cout << "draw Circle\n"; }
};
int main()
{
	Shape* arr[2];	

	Rect r;
	Circle c;

	arr[0] = &r;
	arr[1] = &c;

	for( auto s : arr)
		s->draw();	
}


