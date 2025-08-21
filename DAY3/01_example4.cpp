#include <iostream>


class Shape 
{
	int color;
public:
	virtual ~Shape() {}
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
	Shape* arr[10];	

	Rect r;
	Circle c;

	arr[0] = &r;
	arr[1] = &c;

	for( auto s : arr)
	{
		// 해결책 1. Shape* 인 s 를 Rect* 나 Circle* 타입으로 캐스팅해서 사용 
		// => 그런데, s 가 어떤 도형인지를 먼저 조사해야 한다.
		
		if ( dynamic_cast<Rect*>(s) != nullptr )
		{
			Rect* r = static_cast<Rect*>(s);
			r->draw();
		}
		else if dynamic_cast<Circle*>(s) != nullptr)
		{
			Circle* r = static_cast<Circle*>(s);
			c->draw();
		}
	}
}


