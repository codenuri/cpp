struct Point 
{ 
	int x;
	int y; 
};
// C++ reference 규칙.
// => 너무 중요합니다. 반드시 외워야 합니다.
int main()
{
	Point pt{1, 2};

	// #1. non-const lvalue reference 는 lvalue 만 가리킬수 있다.
	Point& r1 = pt;					// ok.
	Point& r2 = Point{1, 2};		// error.

	// #2. const lvalue reference 는 lvalue 와 rvalue 를 모두 가리킬수 있다.
	const Point& r3 = pt;			// ok
	const Point& r4 = Point{1, 2};	// ok - 되는 이유는 1번소스 참고. 

	// C++98 시절은 위 2개의 규칙만 존재
	// C++11 에서 move 와 perfect forwarding 을 만들기 위해 새로운 문법 도입
	// #3. rvalue reference 는 rvalue 만 가르킬수 있다. (const 없이도 rvalue 가리킬수 있다.)
	Point&& r5 = pt;         // error
	Point&& r6 = Point{1,2}; // ok

	// const rvalue reference 는 어떤 가요 ?
	// => rvalue 만 가리킬수 있는데.
	// => 거의 사용하지 않기 때문에. 중요하지 않고, 대부분 C++기술 문서에서 다루지는 않습니다.
}