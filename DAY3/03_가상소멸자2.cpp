#include <iostream>

class Shape 
{
	int color;
public:
	virtual void draw() { std::cout << "draw Shape\n"; }

	// Shape 는 기반 클래스 이므로 반드시 소멸자를 가상함수로 해야 합니다.
	virtual ~Shape() {}
};

class Rect : public Shape 
{
public:
	virtual void draw() override { std::cout << "draw Rect\n"; }
};

class Circle : public Shape
{
public:
	virtual void draw() override  { std::cout << "draw Circle\n"; }
};

class Triangle : public Shape
{
public:
	virtual void draw() { std::cout << "draw Triangle\n"; }
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


