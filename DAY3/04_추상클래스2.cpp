#include <iostream>

class Shape 
{
	int color;
public:
	virtual ~Shape() {}

	virtual void draw() { std::cout << "draw Shape\n"; }
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


