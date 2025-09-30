struct Point
{
	int x, y;
	Point(int a, int b) : x(a), y(b) {}
};

// 방법 #1. call by value
// 특징 : 복사본 생성
void foo(Point pt){}

// 방법 #2. call by const lvalue reference
// 특징 : 복사본이 없다.
//       상수성이 추가된다.
void foo(const Point& pt) {}

// C++98 기술은 위 2개 밖에 안됨..
// C++11 이후는 아래 2개도 가능

// 방법 #3. 2개 만들기
// => 복사본도 없고, 상수성도 추가 안됨..
// => 원본 그대로 전달.
void foo( Point& )  {}
void foo( Point&& ) {}

// 방법 #4. T&& 를 사용하면 "방법#3" 의 2개를 자동생성할수 있다.
// => 그리고 Point 뿐 아니라 모든 타입에 대해서도 자동생성
template<typename T>
void foo(T&& a) {}


int main()
{
	Point pt{0, 0};
	
	// foo 함수 인자로 lvalue, rvalue 를 모두 보내고 싶다.
	foo(pt);
	foo(Point{0,0});
}
