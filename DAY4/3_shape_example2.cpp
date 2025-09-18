#include <iostream>
#include <vector>

// 핵심 #2. 모든 도형의 공통의 기반 클래스인 Shape 가 있다면
// => 모든 도형의 공통의 특징(color) 한곳에서 관리할수 있게 되고
// => 모든 도형을 하나의 컨테이너에 보관가능 합니다.

class Shape 
{
	int color = 0;
public:
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() { std::cout << "draw rect\n"; }
};
class Circle : public Shape
{
public:
	void draw() { std::cout << "draw circle\n"; }
};

int main()
{
//	std::vector<Rect*> v; // Rect 만 보관 가능한 컨테이너	
	std::vector<Shape*> v;  // 모든 도형을 보관 가능한 컨테이너!!!
							// => 동종(동일 기반 클래스에서 파생된 타입)을 보관하는 컨테이너
}