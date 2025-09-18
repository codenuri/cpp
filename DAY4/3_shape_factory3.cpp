#include <iostream>
#include <vector>
#include <map>


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

class ShapeFactory 
{
	using CREATOR = Shape*(*)();	
	std::map<int, CREATOR> create_map;
public:

	void register_shape(int key, CREATOR c)
	{
		create_map[key] = c;
	}
	Shape* create(int key)
	{
		Shape* s = nullptr;

		auto it = create_map.find(key);
		
		if ( it != create_map.end() )
		{
			s = create_map[key](); 
		}
		return s;
	}




private:
	ShapeFactory() {}	

public:	
	static ShapeFactory& get_instance()
	{
		static ShapeFactory instance;
		return instance;
	}
};


// 아래 클래스는 "공장에 제품을 자동등록" 할때 사용할 클래스 입니다.
// 생성자만 사용합니다.
class AutoRegister 
{
public:
	AutoRegister(int key, Shape*(*c)() )
	{
		ShapeFactory::get_instance().register_shape(key, c);
	}
};

// 전역변수의 생성자가 호출되는 시점을 생각해 보세요

AutoRegister ar{1, &Rect::create};













class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw rect\n"; }

	Shape* clone() const override {	return new Rect(*this); }
	static Shape* create() { return new Rect;}
};




class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw circle\n"; }

	Shape* clone() const override {	return new Circle(*this); }

	static Shape* create() { return new Circle;}
};



int main()
{
	std::vector<Shape*> v; 

	ShapeFactory& factory = ShapeFactory::get_instance();


	factory.register_shape( 1, &Rect::create);
	factory.register_shape( 2, &Circle::create);


	while( 1 )
	{
		int cmd;
		std::cin >> cmd;

		if 	( cmd > 0 && cmd < 8) 
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
