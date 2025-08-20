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
	int n1 = 10; 
	n1 = 20;

	Rect rc = {1,1,10,10};


	// #2. 메모리 구조

	Rect r1 = { 1,1,10,10 }; 
	Rect r2 = { 1,1,10,10 };
}
