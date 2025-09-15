#include <iostream>

struct Point
{
	int x, y;
};
int main()
{
	// 24 page - 중요한 변화.!

	// 기존 C++ 초기화의 문제점
	// => 변수의 종류에 따라 초기화 방법이 다르다
	// => 값만 표기하거나, {} 사용하거나 () 사용
	int n1 = 10;
	int x1[3] = { 1,2,3 };
	Point p1 = { 1,2 };

	// C++11 의 "uniform initialization" 문법
	// => 모든 종류의 변수는 "한가지 동일한 방식으로 초기화 할수 있다."
	int n2 = {10};
	int x2[3] = { 1,2,3 };
	Point p2 = { 1,2 };

	// = 이 없어도 됩니다.
	int n3 {10};
	int x3[3] { 1,2,3 };
	Point p3 { 1,2 };
	
	// direct(직접) initialization : = 이 없는 경우
	// copy(복사)   initialization : = 이 있는 경우
	// => 2개는 약간의 차이가 있지만 
	// => 위 3줄의 경우는 동일. 
	// => 차이는 클래스 문법에서 "explicit constructor" 가 있을때만 차이가 있음. 
}



