#include <iostream>
#include <vector>



class Shape 
{
	int color = 0;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c;}
	virtual int get_area() const { return 0;}
	virtual void draw() { std::cout << "draw shape\n"; }

	virtual Shape* clone() const {	return new Shape(*this); }
};




class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw rect\n"; }

	Shape* clone() const override {	return new Rect(*this); }
};


class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw circle\n"; }

	Shape* clone() const override {	return new Circle(*this); }
};

// 도형을 만드는 공장을 만듭니다.
class ShapeFactory 
{
public:
	Shape* create(int type)
	{
		Shape* s = nullptr;

		if      ( type == 1 ) s = new Rect;
		else if ( type == 2 ) s = new Circle;

		return s;
	}
	// 공장은 여러 객체를 만들필요없습니다
	// 오직 한개만 있으면 됩니다. - singleton 패턴
private:
	ShapeFactory() {}	

public:	
	static ShapeFactory& get_instance()
	{
		static ShapeFactory instance;
		return instance;
	}
};


int main()
{
	std::vector<Shape*> v; 

	ShapeFactory& factory = ShapeFactory::get_instance();

	while( 1 )
	{
		int cmd;
		std::cin >> cmd;

		// 이제 새로운 도형이 추가되어도 아래 코드는 수정될 필요 없습니다.
		if 	( cmd > 0 && cmd < 8) // 1 ~ 7 번은 도형 번호로 예약
		{
			Shape* s = factory.create(cmd);

			if ( s != nullptr )
				v.push_back(s);
		}

		else if ( cmd == 9 )
		{
			for ( auto s : v)
				s->draw();	
		}
		else if ( cmd == 8 )
		{
			std::cout << "몇번째 만들었던 도형을 복제 할까요 >> ";
			int k;
			std::cin >> k;

			v.push_back( v[k]->clone() ); 
		}
	}
}
