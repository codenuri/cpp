// 함수 인자의 원본을 변경할수 없게 하려고 합니다.
// 다음중 좋은 코드는 ?
// => f1 이 좋은 코드!!

void f1(int n) 
{ 
	int k = n;
			// 이순간 복사본 n 에서 한번에 읽는 코드
}


void f2(const int& n) 
{ 
	int k = n;
			// 이 코드에서 n 은 결국 주소. 따라서
			// int k = (*n) 이므로 따라가서 값 꺼내기
			// 이소스를 "godbolt.org" 에 넣으세요
			// f1, f2의 어셈코드 비교
}

int main()
{
	int a = 10;
	f1(a);
	f2(a);
}

// 핵심 정리

// 1. 인자값을 수정하고 싶다.
// => 포인터 또는 레퍼런스로 해야 합니다.
// => 레퍼런스가 안전합니다. "권장!!"
void inc(int* p) {} // p != nullptr 을 확인해야 합니다.
void inc(int& r) {} // r != nullptr 코드 필요 없음. 위 보다 안전

// 2. 인자값을 수정하지 않아야 한다.
// A. int, double 등의 primitive type => call by value 권장
void f1(int n)        {int k = n;} // good
void f2(const int& n) {int k = n;} // bad, n을 사용하는 것은 포인터 를 사용하는것
									// 메모리를 따라가야(dereferencing) 합니다.

// B. 인자가 구조체 등으로 만들어서 크기가 큰경우
void f1(BigSizeType rc) {}		   // bad
void f2(const BigSizeType& rc) {}  // good

// Rect 정도(16byte)는 call by value 도 나쁘지는 않은데.. 보통은 const &
// => 8 바이트 정도 까지는 call by value 권장