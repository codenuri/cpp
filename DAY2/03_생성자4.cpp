#include <iostream>

class Point
{
	int x;
	int y;
public:
	// 핵심 #1. 사용자가 생성자를 한개도 만들지 않으면
	// => 컴파일러가 인자 없는 생성자 제공. 디폴트 생성자 라고 합니다.
	// => 사용자가 한개라만 생성자를 만들면, 컴파일러는 디폴트 생성자 제공안함.
	// => C#, Java, Swift 등 대부분의 언어의 공통의 특징
	Point()             { x=0; y=0; std::cout << "Point()"         << std::endl; } // 1
	Point(int a, int b) { x=a; y=b; std::cout << "Point(int, int)" << std::endl; } // 2
};
int main()
{
	// 핵심 #2. 객체를 만드는 방법
	Point p1;		
	Point p2(1, 2); 	// C++98 스타일

	Point p3{ 1,2 };   	// C++11 이후 가능한 스타일 
	Point p4 = { 1,2 }; // C++11 이후 가능한 스타일 

	// 핵심 #3. 객체를 만들면 항상 생성자가 호출됩니다.
	// => 배열의 경우도 마찬가지..

	Point arr1[5];					// 인자 없는 생성자 5회 호출
	Point arr2[5] = { {1,2},{2,3} };// 인자 있는 생성자 2회 호출, 인자없는 생성자 3회 호출

}