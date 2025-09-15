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

	foo(3);		// int n = 3;
	foo({3});	// int n = {3};
				// C++11 부터 가능한 표기법

	goo(p);		// Point pt = p;
	goo({1,2});	// Point pt = {1,2};
				// C++11 부터 가능하고, 요즘에 아주 널리 사용되는 표기법
}

Point hoo()
{
	return {1,2}; // ok. 요즘에 아주 널리 사용됩니다. 꼭 기억해 두세요.
}




