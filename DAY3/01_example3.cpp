#include <iostream>


class Shape 
{
	int color;
public:
};


class Rect : public Shape 
{
public:
	void draw() { std::cout << "draw Rect\n"; }
};

class Circle : public Shape
{
public:
	void draw() { std::cout << "draw Circle\n"; }
};
int main()
{
	Shape* arr[10];	

	// 다양한 도형을 만들어서 배열에 보관
	Rect r;
	Circle c;

	arr[0] = &r;
	arr[1] = &c;

	// 그리고 사용
	for( auto s : arr)
		s->draw();
}
// 위 코드는 어디서 왜 에러일까요 ??
// => 해결책은 뭘까요 ??

