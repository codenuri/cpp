// 핵심
// const member function 은 선택이 아닙니다. "필수" 문법 입니다.

// 객체의 상태를 변경하지 않은 모든 멤버함수(일명 getter) 는 반드시 상수 멤버함수가 되어야 합니다.

// 아래 getArea() 에서 const 를 붙이지 않은 것은
// => 나쁜 코드가 아닌 "틀린 코드" 입니다.


class Rect
{
	int x, y, w, h;
public:
	Rect(int a, int b, int c, int d)
		: x(a), y(b), w(c), h(d) {}

	int getArea() const { return w * h; }
};

//void foo(Rect r)		// call by value : 복사본 오버헤드 있습니다. 좋지 않은 코드
void foo(const Rect& r)	// 아주 좋은 코드. 반드시 지켜야 하는 코드. 
{
	int n = r.getArea(); // error
}

int main()
{
	Rect r(1, 1, 10, 10); 	// 상수객체 아닙니다.

	int n = r.getArea(); 	// ok. 아무 문제 없습니다.

	foo(r);
}



