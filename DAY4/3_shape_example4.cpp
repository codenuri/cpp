#include <iostream>
#include <vector>

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
			{
				// 해결책 #1. Shape* 인 s 를 Rect* 나 Circle* 로 캐스팅해서 사용
				// => dynamic_cast 로 조사후 캐스팅

				if ( dynamic_cast<Rect*>(s) != nullptr )
				{
					static_cast<Rect*>(s)->draw();		
				}
				else if ( dynamic_cast<Circle*>(s) != nullptr )
				{
					static_cast<Circle*>(s)->draw();	
				}
			}
		}
	}
}
/