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




class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw rect\n"; }

	Shape* clone() const override {	return new Rect(*this); }

	// 자신의 객체를 만드는 static 멤버 함수는 아주 유명한 기술입니다.
	// => 반드시 알아 두세요
	static Shape* create() { return new Rect;}
};

// Rect 를 만드는 2가지 방법
// 1. Rect* rc = new Rect;  	  // new 사용. 반드시 클래스 이름 "Rect" 를 알아야 합니다.
// 2. Rect* rc = Rect::create();  // static 멤버 함수 사용
								  // 클래스 이름을 몰라도, create 함수의 함수 포인터만 알면됩니다.

// C++에서 "클래스" 를 자료구조에 보관할수 없습니다.
//v.push_back("Rect"); // 클래스를 보관한게 아니라, 문자열 보관
   					   // 문자열로는 객체 생성 안됨. 

// 하지만 함수 포인터는 자료구조에 보관가능합니다.
//v.push_back(&Rect::create); // ok. 보관된 함수 포인터로 Rect 생성 가능
							// 즉, Rect를 만들수 있는 데이타를 보관한것.
							// 결국, 클래스 이름을 보관하는 것과 같은 의미.
							// 클래스이름은 객체를 만들기 위한 것이므로















class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw circle\n"; }

	Shape* clone() const override {	return new Circle(*this); }

	static Shape* create() { return new Rect;}
};

class ShapeFactory 
{
	using CREATOR = Shape*(*)(); // 함수 포인터 타입
	
	std::map<int, CREATOR> create_map;	// 도형 생성함수를 보관할 자료 구조

public:

	void register_shape(int key, CREATOR c)
	{
		create_map[key] = c;
	}
	Shape* create(int type)
	{
		Shape* s = nullptr;

		auto it = create_map.find(key);
		
		if ( it != create_map.end() )
		{
			s = create_map[key](); // 현재 map 의 value 는 함수 포인터 입니다.
								   // 따라서 이코드는 함수 포인터로 객체를 생성한것
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
