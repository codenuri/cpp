#include <iostream>
#include <vector>

// 핵심 #3

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
				s->draw();		// A
		}
	}
}
// 위 코드는 어느 부분에서 왜 ? 에러 일까요 ??
// => A 부분에서 에러
// => s 는 Shape* 타입인데.. Shape 에는 draw()함수가 없다!!
// 해결책은 뭘까요 ?
// => 다음소스에서.. 