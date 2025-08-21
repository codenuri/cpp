#include <iostream>

class Shape 
{
	int color;
public:
	virtual ~Shape() {}

	// 가상함수    : 파생 클래스가 override 하지 않으면 디폴트 구현을 제공한다는 의미 
	// 순수가상함수 : 파생 클래스에게 반드시 만들라고 지시하는 것 

//	virtual void draw() { std::cout << "draw Shape\n"; }
	virtual void draw() = 0;
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


