#include <iostream>
// 24page - 중요한 변화.!

struct Point
{
	int x, y;
};
int main()
{
	// 기존 초기화의 문제점
	// => 변수에 종류에 따라 초기화 방법이 다르다. 
	int n1 = 10;
	int x1[3] = { 1,2,3 };
	Point p1 = { 1,2 };

	// C++11 부터 모든 종류의 변수는 {}로 초기화 가능
	// => "uniform initialization(일관된 초기화)" 라는 문법
	int n2 = {10};
	int x2[3] = { 1,2,3 };
	Point p2 = { 1,2 };

	// = 이 없어도 됩니다.
	int n3   {10};
	int x3[3]{ 1,2,3 };
	Point p3 { 1,2 };	

	// = 있는 초기화 : copy initialization
	// = 없는 초기화 : direct initialization
}



