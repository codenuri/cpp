#include <iostream>
#include <vector>

// 핵심 #6

class Shape 
{
	int color = 0;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c;}
	virtual int get_area() const { return 0;}
	virtual void draw() { std::cout << "draw shape\n"; }

	// 자신의 복사본을 만드는 가상함수는 아주 유용하게 사용됩니다.
	virtual Shape* clone() const 
	{
		return new Shape(*this); // 복사 생성자로 생성, 즉 자신(*this) 와 동일한 객체 생성
	}
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
		else if ( cmd == 8 )
		{
			std::cout << "몇번째 만들었던 도형을 복제 할까요 >> ";
			int k;
			std::cin >> k;

			// k 번째 도형이 어떤 도형인지 조사할 필요 없습니다.
			// => 단지 "복사본좀 만들어줘!!" 라고 요청만 하면 됩니다
			v.push_back( v[k]->clone() ); 	// 다형성	
											// 새로운 도형이 추가되어도 
											// 이 코드는 수정될 필요 없습니다.
											
			// java 진영에서 널리 사용되는 용어 입니다. 
			// 의미를 생략해 보세요
			// "Don't Ask, Do It" 
			// 물어보지 말고(조사하지말고) 시켜라!
		}
	}
}
