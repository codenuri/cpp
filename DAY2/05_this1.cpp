// 5_this1.cpp      97 page ~
#include <iostream>

// 객체지향 프로그래밍의 원리에 해당하는 내용 - 반드시 이해 해 두세요!!
// => 대부분의 객체지향 언어의 공통의 특징

class Point
{
	int x, y;
public:
	// 사용자 코드			 // 컴파일러가 변경한 코드. 
	void set(int a, int b)  // void set(Point* this, int a, int b) 
	{						// {
		x = a;				//		this->x = a;
		y = b;				//		this->y = b;	
							//	
		// 멤버 함수안에서 의 this 의미 
		// => 현재 함수를 호출할때 사용한 객체의 주소. 
		std::cout << this << std::endl;
	}
};
int main()
{
	Point p1;
	Point p2;
	std::cout << "p1 : " << &p1 << std::endl;
	std::cout << "p2 : " << &p2 << std::endl;

	p1.set(10, 20); // 이 코드는 컴파일러에 의해
					// set(&p1, 10, 20)  처럼 변경됩니다.
	p2.set(10, 20);				
}
