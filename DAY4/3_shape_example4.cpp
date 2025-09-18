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

class Triangle : public Shape
{
public:
	void draw() { std::cout << "draw triangle\n"; }
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
// 위 해결책 #1. OCP 를 위반한 코드 입니다

// 기능 확장에는 열려있고(Open, 나중에 새로운 클래스/모듈이 추가되어도)
// 코드 수정에는 닫혀있어야(Close, 기존 코드는 수정되지 말아야 한다는)
// 이론(principle)

// OCP(Open-Close Principle) 이론..

// 위 코드는 Triangle 추가시 if 문이 추가 되어야 합니다.
// => OCP 위반 입니다.

// 객체 지향 S/W 설계의 5개 원칙
// SRP, OCP, LSP, ISP, DIP => SOLID 원칙
// 