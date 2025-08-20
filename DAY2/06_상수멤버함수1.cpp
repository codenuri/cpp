// 4_상수멤버함수1.cpp    104page~
#include <iostream>

// const member function
// => 너무나 중요한 모든 C++ 개발자가 반드시 정확히 알고 사용해야 하는 문법
// => 그런데, 현실은 너무나 잘못알고, 제대로 사용하지 않는 문법!!



class Point
{
public:
	int x, y;

	Point(int a, int b ) : x(a), y(b) {}

	void set(int a, int b) { x = a; y = b; }

	// const member function
	// => 멤버 함수 안에서 멤버 값을 변경하지 않을것이라고 컴파일러에게 알리는 작업
	// => 상수 객체라도 상수멤버함수는 호출 가능하다.
	// => 단, 상수멤버함수 안에서는 멤버 값 변경 안됨.
	void print() const 
	{	 
//		x = 100; // error
		std::cout << x << ", " << y << std::endl;
	}
};
int main() 
{
	// 핵심 : p 가 상수 객체 입니다.
	const Point p(1, 2);

	p.x = 10;		// error. x 는 public 이지만 "상수객체"	이므로
	p.set(10, 20);	// error. 
	p.print();		// error
					// 단, 상수 멤버 함수라면 에러 아님. 

	// 핵심 : 상수객체는 "상수 멤버함수만 호출" 할수 있다.
}

