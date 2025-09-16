#include <iostream>

// 아래 코드의 결과를 예측해 보세요

class Point
{
public:
	int x, y;

	// 초기화 리스트는 "대입"이 아닌 진짜 초기화 입니다.
	// 초기화는 만들면서 넣는것 입니다.
	// 즉, 아래 코드는 "코드 순서" 로 실행되지 않고
	// 멤버가 선언된 순서로 실행됩니다.
	// => B 먼저 실행후, A 실행
	//			A	B
//	Point() : y{0}, x{y}
	Point() : x{0}, y{x}
	{		
	}

	// 해결책, 권장 코드
	// => 초기화 리스트 작성시, 
	// => 되도록, 멤버가 놓은 순서로 코드를 작성하세요
};

int main()
{
	Point pt;

	std::cout << pt.x << std::endl; // 쓰레기값
	std::cout << pt.y << std::endl; // 0
}




