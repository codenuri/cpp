// QA.cpp
// 아까 4번에서 C++에서 struct와 class 차이는 멤버의 디폴트 범위지정밖에 없는데 
// => "정확합니다." 

// 왜 struct는 초기화 리스트가 가능하고, 
// class 는 해당하는 생성자가 있어야 되는건가요?
// => "struct 와 class 차이가 아닌, 디폴트 생성자가 있는가 여부"

class Point1 
{
	// 사용자가 만든 생성자가 한개도 없습니다.
	// 컴파일러가 디폴트 생성자 제공
};
class Point2
{
public:
	Point2(int a, int b) {}
	// 사용자가 만든 생성자가 한개 있습니다.
	// 컴파일러가 디폴트 생성자 제공하지 않습니다.	
};

class Rect 
{
	Point1 from;
	Point2 to;

public:
	Rect()
	{
		// class Point1::Point1() <= ok..    디폴트 생성자 있음
		// class Point2::Point2() <= error.. 디폴트 생성자 없음. 
	}
};