// 인자로 전달된 원본 변수를 수정되지 않게 하려고 합니다.
// 다음 f1, f2 중 좋은 코드는 ?
// 아래 코드는 "godbolt.org" 에 넣고 A, B의 어셈블리 코드 차이를 확인하세요
void f1(int n) 
{ 
	int k = n; 	// A
}
void f2(const int& r) 
{ 
	int k = r; // B. r 은 결국 포인터.. 따라서 이코드는
//  int k = *(r의내부포인터)

}
int main()
{
	int x = 10;
	f1(x);
	f2(x);
}
// 함수 인자 방식 정리
// #1. 함수 인자로 전달된 변수를 변경하려면
// => pointer 또는 reference..
// => 그런데 reference가 안전
// ex) void inc(int& r) { ++r;}

// #2. 함수 인자로 전달된 변수를 변경하지 않으려면
// A. 인자의 타입이 primitive type(int, double 등)
// => call by value
// ex) void f1(int n) {int k = n;}

// B. 인자의 타입이 user define type 이고 크기가 큰 경우
// (보통 16 이상일때, 복사생성자가 있을때)
// => const & 가 좋다.
// ex) void draw(const Rect& rc) {}

// 구글에서 "C++ core guideline" 검색후, 1번째 링크로 이동
// => C++창시자와 C++표준위원장을 지낸 herb shutter 가 만드는 가이드라인.


// QA) call by value를 할 때도 const를 쓰면 좋나요?
void f1(int age) 
{ 
	age = 10; // ok. 복사본에 대한 변경
}

void f1(const int age) 
{ 
	age = 10; // error. 복사본도 변경하지 않겠다는 의미
			  // 안전성을 위해서는 좋은 코드
			  // 논리적으로 변경이 필요 없는 변수라면!!
}