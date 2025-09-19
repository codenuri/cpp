#include <iostream>
#include <vector>

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
