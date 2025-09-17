#include <iostream>
// 핵심 #1. 멤버 함수의 1번째 인자로 this 가 추가됩니다. - "this call" 이라고 합니다.
// 핵심 #2. static 멤버 함수의 1번째 인자로 this 가 추가안됩니다.

class Point
{
	int x, y;
public:
	// 사용자 코드				  // 컴파일러가 변경한 코드
	void set(int a, int b) 		// void set(Point* this, int a, int b) 
	{							// {
		x = a;					//		this->x = a;
		y = b;					//		this->y = b;	<== 이렇게  변경됩니다.

		// 멤버 함수 안에서 사용되는 this
		// => 현재 멤버 함수를 호출할때 사용한 객체의 주소
		std::cout << this << std::endl;
	}
	static void foo(int a)	// void foo(int a) <= 컴파일 후에도 this 는 추가 안됨.
	{
		x = a;				// 		this->x = a; 로 변경되어야 하는데,,
	}						//					 static 멤버 함수는 this 가 없어서 error
							//                   그래서, static 멤버 함수에서는 
							//				     멤버 데이타 접근 안됨. 
};
int main()
{
	Point::foo(3); // static 멤버 함수는 객체 없이 호출

	Point p1;
	Point p2;
	std::cout << "p1 : " << &p1 << std::endl;
	std::cout << "p2 : " << &p2 << std::endl;

	p1.set(10, 20); // set(&p1, 10, 20) 으로 변경됩니다
	p2.set(10, 20); // set(&p2, 10, 20) 으로 변경됩니다
}
