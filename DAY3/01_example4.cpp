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
		else if (dynamic_cast<Circle*>(s) != nullptr)
		{
			Circle* c = static_cast<Circle*>(s);
			c->draw();
		}
	}
}

// 위 코드는 새로운 도형 "Triangle" 이 추가되면
// 위 else if 구문이 또 추가되어야 합니다.
// 즉, 코드 수정이 많아 집니다.

// 기능확장에 열려 있고(Open, 새로운 모듈, 클래스가 추가되어도)
// 코드수정에는 닫혀 있어야(Close, 기존 코드는 변경되지 않게)
// 만들라는 이론(Principle)
// OCP 이론. 
