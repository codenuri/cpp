#include <iostream>

// 동일 이름의 함수를 아래 처럼 오버로딩 가능합니다
// => 아래 주석 반드시 외우세요.. move 필수..!
void foo(Point&  pt) {std::println("1. Point&"); }
void foo(Point&& pt) {std::println("2. Point&&");}
void foo(const Point&  pt) {std::println("3. const Point&");}

int main()
{
	Point pt{1, 2};


	foo( pt );			// pt는 lvalue
						// 1번 Point& 버전 호출
						// (1) 이 없으면 3번 호출 

	foo( Point{1,2} );	// temporary 이므로 rvalue
						// 2번 Point&& 버전 호출
						// (1) 없으면 3번 호출. 

}


