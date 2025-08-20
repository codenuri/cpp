#include <iostream>

// 아래 코드 결과 예측해 보세요

class Point
{
public:
	int x, y;

	// 초기화 리스트는 대입이 아닌 초기화 입니다.
	// => 따라서, 초기화 리스트의 코드 순서가 아닌,
	// => 멤버가 놓인 순서대로 실행됩니다.
	// => 아래 코드는 B, A 순서로 실행
	// => 해결책 : 반드시 멤버가 선언된 순서대로 초기화 리스트 코드를 작성하세요
	//		  A     B
//	Point() : y(0), x(y)		// <= 버그!!
	Point() : x(0), y(x)
	{
	}
};
int main()
{
	Point pt;

	std::cout << pt.x << std::endl; // 쓰레기값
	std::cout << pt.y << std::endl; // 0
}




