#include <iostream>

struct Rect
{
	int left;
	int top;
	int right;
	int bottom;

	int getArea() { return (right - left) * (bottom - top); }
	void draw() { std::cout << "draw rect" << std::endl; }
};
int main()
{
	// #1. 용어
	int n1 = 10;  // n1 은 "변 하는 수" 입니다.
	n1 = 20;	  // 그래서, n1 을 "변수" 라고 부릅니다.	
				    
	Rect rc = {1,1,10,10}; // rc 는 사각형 한개를 나타냅니다.
						   // "변수" 라는 용어보다는 "객체" 라는 용어를 사용합니다

	// "객체" : 세상에 존재 하는 모든 것들!!!
	//          rc 는 메모리에 존재하는 사각형

	// 일부 언어에서는 n1 도 "변수" 보다 "객체"라고 하는 경우도 있습니다.

	// C++에서는 관례적으로
	// int, double 등을 메모리에 만든것      : 변수
	// user define 타입 등을 메모리에 만든것 : 객체

	// 참고 : Rust 는 모든 것을 "변수" 라고 부릅니다.
	//-----------------------------------재----------

	// #2. 메모리 구조
	// 객체 생성시
	// => 멤버 데이타는 객체당 한개씩 생성 - 스택
	// => 멤버 함수는 객체 갯수에 상관없이 코드메모리에 한개만 존재

	Rect r1 = { 1,1,10,10 }; 
	Rect r2 = { 1,1,10,10 };

	std::cout << sizeof(r1) << std::endl;
}
