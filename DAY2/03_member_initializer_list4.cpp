#include <iostream>

class Point
{
	int x, y;
public:
	Point()				: x{0}, y{0} { std::cout << "Point()" << std::endl; }
	Point(int a, int b) : x{a}, y{b} { std::cout << "Point(int, int)" << std::endl; }
};

class Rect
{
	Point ptFrom;
	Point ptTo;
public:
	Rect()
	{	
		// 컴파일러가 Rect 생성자 제일 윗부분에 아래 코드를 추가 합니다.
		// => 이소스 "godbolt.org" 에 넣으세요, 
		// => main 기계어(어셈코드), 
		// => Rect 생성자 기계어(어셈코드) 보세요
		// call Point::Point() <= ptFrom 에 대해서 디폴트 생성자 호출하는 코드
		// call Point::Point() <= ptTo   에 대해서 디폴트 생성자 호출하는 코드

		std::cout << "Rect()" << std::endl;
	}
};
int main()
{
	// 객체를 생성하면 항상 생성자가 호출됩니다.
	// => 아래 코드 실행결과 예측해 보세요
	Rect r; 	// call Rect::Rect(), 즉, 이순간은 Rect() 생성자만 호출. 
}




