#include <iostream>

struct Point
{
	int x, y;
};
void foo(int n)    {} 
void goo(Point pt) {}

int main()
{
	Point p = { 1,2 };

	foo(3);    // int n = 3;
	foo({3});  // int n = {3};

	goo(p);		// Point pt = p;
	goo({1,2});	// Point pt = {1,2};
				// C++11 이후 부터는 함수 인자로 이렇게 사용가능
				// {} 초기화 이후 , 코드 유연성이 아주 좋아졌습니다.
}





