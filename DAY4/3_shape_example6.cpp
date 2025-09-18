#include <iostream>
#include <vector>

// 핵심 #5. 다형성
// => OCP 를 만족하는 좋은 코드 입니다.
// => 이예제에 Triangle 이 나중에 추가 되어도
// => "s->draw()" 는 수정될 필요가 없습니다. OCP 만족. 

class Shape 
{
	int color = 0;
public:
	virtual ~Shape() {}


	void set_color(int c) { color = c;}
	virtual int get_area() const { return 0;}
	virtual void draw() { std::cout << "draw shape\n"; }
};




class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw rect\n"; }
};
class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw circle\n"; }
};

class Triangle : public Shape
{
public:
	void draw() override { std::cout << "draw triangle\n"; }
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
				s->draw();	// 다형성(polymorphism)
							// => 동일한 표현식(코드가)이 상황(실제 객체가 무엇인가)
							//    에 따라 다르게 동작하는것

							// 객체 지향의 3대 특징 : 캡슐화, 상속, 다형성


		}
	}
}
