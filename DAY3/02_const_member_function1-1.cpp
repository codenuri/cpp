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
	// 의 정확한 원리 
	// => 결국, this 이야기!!! 그래서 this 가 중요

	//       Point* this = &const Point; // error. 상수의 주소를 비상수 포인터에 담을수 없다
	// const Point* this = &const Point; // ok
//	void print()  		// void print(Point* this)
	void print() const	// void print(const Point* this)
	{	
//		x = 10; // this->x = 10 인데..
				// this 는 const * 이므로 값 변경 안됨.
				// error
		std::cout << x << ", " << y << std::endl;
	}
};
int main() 
{
	const Point p{1, 2};
	
	p.print();	// print(&p);
}
// 어려운분은 "상수 객체는 상수 함수만 호출가능하다" 만 외우세요
// 잘하는분은 "위 원리 반드시 이해 하세요" C++의 내부 원리!!
