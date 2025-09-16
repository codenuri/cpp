#include <iostream>

class Point
{
	int x, y;
public:
//	Point()				: x{0}, y{0} { std::cout << "Point()" << std::endl; }
	Point(int a, int b) : x{a}, y{b} { std::cout << "Point(int, int)" << std::endl; }
};
class Rect
{
	Point ptFrom;
	Point ptTo;
public:
	// 멤버 데이타인 Point 타입에 디폴트 생성자가 없으면
	// => 아래 코드는 컴파일 에러 입니다.
	// => 컴파일러가 추가한 코드에서 Point 의 디폴트 생성자를 호출하고 있으므로. 
	/*
	Rect()
	{	
		// call Point::Point() <= ptFrom 에 대해서 디폴트 생성자 호출하는 코드
		// call Point::Point() <= ptTo   에 대해서 디폴트 생성자 호출하는 코드
		std::cout << "Rect()" << std::endl;
	}
	*/

	// 해결책 : 컴파일러가 코드를 생성할때 Point 의 디폴트 생성자가 아닌 다른 생성자를
	//			호출하도록 해야 합니다.
	//			초기화 리스트에 표기하면 됩니다.
	// 현재 코드 "godbolt.org"에 넣고 Rect 생성자에서 Point 생성자 호출하는 코드가 어떻게
	// 변경되었는지 확인하세요. 
	Rect() : ptFrom{0, 0}, ptTo{1, 1}
	{	
		// 사용자가 작성한 초기화 리스트 코드 때문에 컴파일러가 만드는 코드가 아래 처럼 변경됩니다.
		// call Point::Point(0, 0) 
		// call Point::Point(1, 1) 
		std::cout << "Rect()" << std::endl;
	}
};
int main()
{
	Rect r; 	
}

// 결론 
// => 초기화 리스트의 정확한 의미는
// => 멤버 데이타의 생성자를 호출하는 방법을 컴파일러에게 알려주는 것.
// => 4.cpp, 4-1.cpp 의 Rect 생성자의 어셈을 잘 비교해 보세요. 


