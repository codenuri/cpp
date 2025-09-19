#include <iostream>
#include <vector>

class Shape 
{
	int color = 0;
public:
	virtual ~Shape() {}
	
	void draw() 
	{ 
		std::cout << "mutex.lock\n";
		draw_imp();		
		std::cout << "mutex.unlock\n"; 
	}

	// 가상함수     : 파생 클래스가 override 하지 않으면 기본 구현 제공하겠다는 의도	
	// 순수가상함수 : 파생 클래스가 반드시 override 해야 한다고 지시하는 것
	//			    즉, "반드시 구현부을 제공해라" 라고 시키는 것
protected:
//	virtual void draw_imp() { std::cout << "draw shape\n"; 	}  // 나쁜 코드
	virtual void draw_imp() = 0;	// 좋은 코드!

public:
//	virtual Shape* clone() const {	return new Shape(*this); }
	virtual Shape* clone() const = 0;
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
