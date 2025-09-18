#include <iostream>
#include <vector>

// 핵심 #6. 디자인 패턴이란 ?
// => 1994년 4명의 개발자가 만든 책의 제목
// => 당시 유명한 오픈소스를 분석해서 공통으로 사용되는 코딩 기법에 "이름을 부여" 한것
// => 23개의 이름
// => 저자 4명이 만든것이 아니라, 단지 이름만 부여 한것
//    그래서 4명의 도둑이라는 의미로 "gang's of four" => GOF's 디자인 패턴이라고 합니다.


// 핵심 #7. prototype 디자인 패턴
// => 객체의 복사본이 필요하면 clone() 같은 가상함수를 만들자는 것
// => 정확히는 다음 시간에 등장


// 핵심 #8. 리팩토링에서 사용되는 용어 입니다. 의미를 이해해 보세요

// "replace conditional with polymorphism"
// "당신의 코드에 제어문(if, switch) 이 있다면 다형성(가상함수)로 변경하는 것을 고려하라!"
//	example7.cpp 의 dynamic_cast 와 if 를 example8.cpp 의 clone() 가상함수로 변경
// => OCP 를 만족하는 디자인이 된다.

// 학습순서
// C++문법 => 디자인 패턴 => 리팩토링 순서이어야 이해 가능합니다.



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
