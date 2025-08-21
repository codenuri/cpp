#include <iostream>

// 파워 포인트 값은 프로그램을 객체지향으로 만든다고 생각해 봅시다.

// 1. 각각의 도형을 타입으로 설계 합니다.

class Rect 
{
	// int x, y, w, h, 생성자.. => 생략
	//							  이번예제는 가상함수에 집중.. 
public:
	void draw() { std::cout << "draw Rect\n"; }
};

class Circle 
{
public:
	void draw() { std::cout << "draw Circle\n"; }
};
int main()
{
	Rect* arr[10];	
}
