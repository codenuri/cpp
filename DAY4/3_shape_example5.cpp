#include <iostream>
#include <vector>

// 핵심 #3. 모든 도형의 공통의 특징은 기반 클래스(Shape)에도 있어야 한다.
// => 그래야 Shape* 로 draw() 호출 가능
// => 문법적 규칙이 아닌 디자인 규칙

class Shape 
{
	int color = 0;
public:
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() { std::cout << "draw rect\n"; }
};
class Circle : public Shape
{
public:
	void draw() { std::cout << "draw circle\n"; }
};

int main()
{
	std::vector<Shape*> v; 

	while( 1 )
	{
		int cmd;
		std::cin >> cmd;

		if 		( cmd == 1 ) v.push_back(new Rect);
		else if ( cmd == 2 ) v.push_back(new Circle);
		else if ( cmd == 9 )
		{
			for ( auto s : v)
				s->draw();		
		}
	}
}
