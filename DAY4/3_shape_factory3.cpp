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

// 전역변수의 생성자가 호출되는 시점을 생각해 보세요
// => main 함수가 호출되기 전에 생성자 실행
// => 즉, 아래 코드가 있으면 main 함수가 시작되기 전에 이미 Rect 는 공장에 등록됨
// AutoRegister ar{1, &Rect::create};


class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw rect\n"; }

	Shape* clone() const override {	return new Rect(*this); }

	static Shape* create() { return new Rect;}

	// static 멤버 데이타의 특징을 생각하세요
	// => 객체가 없어도 메모리에 생성됨.
	// => 즉, main 함수 이전에  ar의 생성자 호출됨
	// => 따라서 공장에 Rect 등록됨.!
	// [참고] C++17 의 inline static 사용하면 외부 정의 필요 없습니다.
	inline static AutoRegister ar{1, &Rect::create};
};

// static 멤버 데이타는 클래스 외부에 아래 처럼 만들어야 하는데.
// 결국 아래 코드가 전역변수 처럼 "Rect" 객체가 없어도 메모리에 생성되는것
// AutoRegister Rect::ar{1, &Rect::create}; 






class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw circle\n"; }

	Shape* clone() const override {	return new Circle(*this); }

	static Shape* create() { return new Circle;}

	inline static AutoRegister ar{2, &Circle::create};
};



int main()
{
	std::vector<Shape*> v; 

	ShapeFactory& factory = ShapeFactory::get_instance();

	// 아래 코드가 없어도 이미 도형은 공장에 등록되었습니다.
//	factory.register_shape( 1, &Rect::create);
//	factory.register_shape( 2, &Circle::create);


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
