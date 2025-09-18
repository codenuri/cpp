#include <iostream>
#include <vector>

// 핵심 #3. 모든 파생클래스(도형)의 공통의 특징은 기반 클래스(Shape)
//          에도 있어야 한다.
// => 그래야 Shape* 로 draw() 호출 가능
// => 문법적 규칙이 아닌 디자인 규칙


// 핵심 #4. 기반 클래스가 가진 멤버 함수중에서 파생 클래스가 override 하게되는 것은
//          반드시 가상함수로 만들어야 한다.

class Shape 
{
	int color = 0;
public:
	virtual ~Shape() {}

	// 아래 함수는 virtual 로 할까요 ? non-virtual 로 할까요 ?
	// => 파생 클래스가 override 할 이유 없습니다
	// => non-virtual
	// => virtual 로 해도 되긴 하지만, virtual 은 느립니다.
	// => override 할 이유 없다면 빠른게 좋습니다
	void set_color(int c) { color = c;}

	// 아래 함수는 virtual ? non-virtual ?
	// => 모든 도형은 면적을 구하는 방법이 다릅니다.
	// => 따라서 아래 함수는 파생 클래스가 override 하게 됩니다.
	// => virtual !!
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
