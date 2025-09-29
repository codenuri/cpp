#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) : x{a}, y{b} { std::cout << "Point()\n"; }	
	
	~Point() { std::cout << "~Point()\n"; }
};

int main()
{
//	Point pt(1,2); // 이름이 있는 객체(named object)
				   // => 이름이 있으므로 다음 문장에서 사용가능
				   // => 수명 : 자신을 선언한 {}을 벗어 날때 파괴. 

//	Point (1,2);	// 이름이 없는 객체(unnamed object)
					// => 이름이 없으므로 다음 문장에서 사용할수 없다.
					// => 수명 : 자신을 선언한 문장의 끝(;)

	Point(1, 2), std::cout << "X\n";
	
	std::cout << "---------------------\n";
}
