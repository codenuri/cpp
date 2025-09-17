
// 상수 멤버 함수 문법은
// => 선택이 아닙니다. 필수 입니다.

// => 객체의 상태를 변경하지 않은 모든 멤버 함수(getter, get~ 형태의 함수)
//    는 반드시 const member function 으로 해야 합니다.

// => 아래 get_area() 에 const 를 빼면 완전히 틀린 코드입니다.

class Rect
{
	int x, y, w, h;
public:
	Rect(int a, int b, int c, int d) : x{a}, y{b}, w{c}, h{d} {}

//	int get_area() { return w * h; } // 나쁜 코드가 아닌 틀린코드
	int get_area() const { return w * h; } // 이게 맞는 코드
};

//void foo(Rect r) 		// call by value : 복사본 오버헤드. 나쁜 코드
void foo(const Rect& r) // ok. 좋은 코드, C++에서 가장 널리 사용되는 방식
{
	int n = r.get_area(); //?
}

int main()
{
	Rect r{1, 1, 10, 10};	// 상수 객체 아님. 
	int n = r.get_area(); 	// ok
	foo(r);
}



