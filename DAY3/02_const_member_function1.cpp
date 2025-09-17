#include <iostream>

// 상수 멤버 함수 문법
// => 초급 문법인데,
// => 제대로 이해하는 개발자가 별로 없습니다.
// => 반드시 완벽히 이해해야 합니다.

class Point
{
public:
	int x, y;
	
	Point(int a, int b) : x{a}, y{b} {}

	void set(int a, int b) { x = a; y = b; }

	// 상수 멤버 함수(const member function)
	// => 멤버 함수 () 뒤에 const 를 붙이는 문법
	// => 특징 #1. 상수 객체라도 호출 가능하다.
	// => 특징 #2. 상수 멤버 함수 안에서는 멤버 데이타의 값을 변경할수 없다. 
	void print()  const 
	{	
		x = 10; // error. 상수 멤버 함수에서는 멤버 값 변경 못함. 

		std::cout << x << ", " << y << std::endl;
	}
};
int main() 
{
	// 핵심 : 객체 p는 상수 입니다.
	const Point p{1, 2};

	p.x = 10;		// error. x 는 public 이지만 p 가 상수 객체 이므로	
	p.set(10, 20);	// error. 
	p.print();		// error. 	
					// 단, print 가 const member function 이라면 ok
	// 반드시 외워야 하는 것
	// => 상수 객체는 상수 멤버 함수만 호출 할수 있다. <== 아주 중요
}

