#include <iostream>

// reference : "기존 변수를 가리키는 별명" 이라고만 표준 문서에 정의 되어 있지만
//             대부분의 컴파일러는 결국 내부적으로 포인터 변수를 만들어서 사용

int main()
{
	int n = 3;

	int* p1 = &n;
	int& r1 = n;   // r1은 결국 내부적으로 포인터

	// #1. 아래 2줄에 대한 기계어 코드 비교해 보세요(godbolt.org)
	// => 결국 대부분의 환경에서 동일
	*p1 = 10;
	r1  = 10; 	   // 결국 이코드는 (*r1) = 10;

	// #2. reference 는 안전한 포인터 입니다.
	int* p2; 			// 포인터는 초기화 하지 않거나
	int* p3 = nullptr;  // 0으로 초기화 가능합니다.

	int& r2;			// error. reference 는 초기값이 없으며 에러
	int& r3 = nullptr;  // error. 0을 가리키는 reference 도 만들수 없습니다.
	int& r3 = n; 	    // ok. 항상 유효한 변수를 가리 켜야 합니다.
}
// 함수 인자를 만들때
void f1(int* p) 
{
	// 포인터라면 유효한지 확인하고 사용해야 합니다.
	if ( p != nullptr ) // 안전하게 만들려면 반드시 필요
	{
		*p = 10;
	}
}
void f2(int& r) 
{
	// 인자가 reference 라면 항상 유효!! 바로 사용가능
	r = 10;
}

f1(nullptr); // ok
f2(nullptr); // error. 유효한 변수를 보내야 한다.