#include <iostream>

// 1. 모든 파생클래스(도형)의 공통의 특징은 기반 클래스에도 있어야 한다.
// => 문법적인 규칙이 아니라 디자인적인 규칙
// => 그래야, 기반 클래스 포인터로 해당 특징 사용가능.

// 2. 기반 클래스 함수중 파생 클래스가 재정의 하게 된다면
//    반드시 가상함수로 만들어야 한다.
//    그래야, 기반 클래스 포인터로 호출시
//    파생 클래스 함수 호출

class Shape 
{
	int color;
public:
	virtual void draw() { std::cout << "draw Shape\n"; }
};

class Rect : public Shape 
{
public:
	virtual void draw() { std::cout << "draw Rect\n"; }
};

class Circle : public Shape
{
public:
	virtual void draw() { std::cout << "draw Circle\n"; }
};

class Triangle : public Shape
{
public:
	virtual void draw() { std::cout << "draw Triangle\n"; }
};
int main()
{
	Shape* arr[2];	

	Rect r;
	Circle c;

	arr[0] = &r;
	arr[1] = &c;

	for( auto s : arr)
		s->draw();	// 다형성(polymorphism)
				    // => 동일한 한줄의 코드가
					//    상황(실제 객체)에 따라 다르게 동작하는 것

	// 객체지향 프로그래밍의 3대 특징
	// => 캡슐화, 상속, 다형성

	// 다형성 장점
	// => 새로운 도형(Triangle) 이 추가되어도 
	//    다형성 기반의 코드는 수정될 필요 없다.
	// => OCP 만족 
}


