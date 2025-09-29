class Point
{
public:
	int x, y;
	Point(int a, int b) : x{a}, y{b} { }	
};


void f1(Point  pt) {} // call by value     : 복사본 생성
void f2(Point& pt) {} // call by reference : 복사본 생성 안됨
// -----------------------------------------------------------------------


Point pt{1, 1};

Point foo() // return by value
{
	return pt;	// pt 를 반환하는 것이 아니라, 복사본을 만들어서 반환하는 것
				// call by value 와 동일한 의미
				// 리턴용 복사본은 이름이 없는 객체(temporary)
				// 함수 호출 문장의 끝에서 파괴
}

Point& goo()  // return by reference : 리턴용 복사본을 만들지 말고 pt의 별명을 반환
{
	return pt;
}

int main()
{
	foo().x = 10; // error. 리턴용 임시객체(rvalue) 에 값을 넣는 코드!!!

	goo().x = 10; // ok.    "pt별명.x = 10"
}

// temporary
// 1. 사용자가 의도적으로 만들기도 하고
// => 주로 함수 인자 (draw_line(Point{1,1}, Point{5,5}));

// 2. 사용자가 만든 코드의 결과로 생성되기도 합니다.
// => 값을 반환하는 함수 ( Point foo() )

// temporary : 이름이 없이 임시로 사용하므로 rvalue!