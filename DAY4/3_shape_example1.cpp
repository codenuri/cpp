#include <iostream>
#include <vector>

// 파워 포인트 값은 프로그램을 객체지향으로 만든다고 생각해 봅시다.

// 핵심 #1. 모든 도형을 타입으로 설계하면 편리합니다

class Rect 
{
//	int x, y, w, h; 생성자...등은 생략
public:
	void draw() { std::cout << "draw rect\n"; }
};
class Circle
{
public:
	void draw() { std::cout << "draw circle\n"; }
};

int main()
{
	
}