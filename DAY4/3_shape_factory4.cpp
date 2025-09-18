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


// 아래 클래스는 "공장에 제품을 자동 등록" 할때 사용할 클래스 입니다.
// 생성자만 사용합니다.
class AutoRegister 
{
public:
	AutoRegister(int key, Shape*(*c)() )
	{
		ShapeFactory::get_instance().register_shape(key, c);
	}
};

// 이제 모든 새로운 도형을 만들때는 
// 1. create() 라는 static 멤버 함수와
// 2. AutoRegister 타입의 이라는 static 멤버 데이타가 있어야 합니다.
// => 이 규칙을 자동생성하는 매크로를 도입하면 편리합니다.
// => Unreal 같은 엔진에서 많이 사용하는 기술!!

#define REGISTER(key, classname)							\
	static Shape* create() { return new classname;}			\
	inline static AutoRegister ar{key, &classname::create};



class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw rect\n"; }

	Shape* clone() const override {	return new Rect(*this); }

	REGISTER(1, Rect)
};




class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw circle\n"; }

	Shape* clone() const override {	return new Circle(*this); }

	REGISTER(2, Circle)
};

class Triangle : public Shape
{
public:
	void draw() override { std::cout << "draw triangle\n"; }

	Shape* clone() const override {	return new Triangle(*this); }

	REGISTER(3, Triangle)
};


int main()
{
	std::vector<Shape*> v; 

	ShapeFactory& factory = ShapeFactory::get_instance();

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
