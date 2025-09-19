#include <iostream>
#include <vector>

// template method 패턴
// => 기반 클래스에서 변하지 않은 공통의 흐름을 담을 "non-virtual function" 을 제공하는데
//    변해야 하는 부분만 가상함수로 분리한다.

// => 파생 클래스는 변하는 부분만 override 할수 있는 기회를 가지게 된다.
// => 객체지향 디자인의 핵심이 되는 패턴. 

class Shape 
{
	int color = 0;
public:
	virtual ~Shape() {}

	// 핵심 : 공통성과 가변성의 분리
	// => 변하지 않은 코드 내부에 있는 변하는 부분을 찾아서 분리 한다.
	// => 변해야 하는 부분은 "가상함수"로 분리 한다.

	// 실제 그림을 그릴때는 아래 함수를 직접 호출하면 안되고
	// draw() 통해서만 호출되어야 한다.
	// protected 또는 private
protected:
	virtual void draw_imp() 
	{
		std::cout << "draw shape\n";
	}

public:
	void draw() 
	{ 
		std::cout << "mutex.lock\n";

		draw_imp();
		
		std::cout << "mutex.unlock\n"; 
	}



	virtual Shape* clone() const {	return new Shape(*this); }
};



class Rect : public Shape
{
public:
	void draw_imp() override { std::cout << "draw rect\n"; }

	Shape* clone() const override {	return new Rect(*this); }
};


class Circle : public Shape
{
public:
	void draw_imp() override { std::cout << "draw circle\n"; }

	Shape* clone() const override {	return new Circle(*this); }
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
