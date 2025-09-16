#include <iostream>

// godbolt.org 에 접속후 아래 코드 5~13 줄까지 복사해 넣으세요

// 핵심 #1. C++ reference 는 대부분의 컴파일러가 내부적으로 포인터로 구현합니다.
// => 단, C++ 표준문서에서 "항상 포인터로 구현한다" 라고 되어 있지 않으므로
//    컴파일러에 따라 다를수 있습니다.

int main()
{
	int n1 = 10;

	int* p1 = &n1;
	int& r1 = n1;	// r1은 결국 내부적으로 포인터 입니다.

	*p1 = 20;
	r1 = 20;		// 이 코드는 "(*r1의내부포인터) = 20" 의 원리.
					// 즉 위와 동일.
	// reference 가 결국 포인터 라면 그냥 포인터를 사용하면 되는데..
	// 왜 reference 를 만들었나요 ?
	// => reference 는 "안전한 포인터" 입니다.

	int* p2;			// OK. 나쁜 코드지만 컴파일 에러 아님.
	int* p3 = nullptr;	// OK. 포인터는 대상 체가 없을수도 있다.

	int& r2;			// ERROR. reference 는 반드시 초기화 필요
	int& r3 = nullptr;	// ERROR. reference 는 반드시 유효한 메모리를 가리켜야 합니다.

	// reference 는 항상 유효한 메모리를 가리키지 않으면 에러 입니다.
}

void f1(int* p) 
{
	// 포인터를 안전한 코드를 작성하려면 아래 처럼 null check 가 필요합니다.
	if ( p != nullptr )
	{
		*p = 10;
	}
}

void f2(int& r) 
{
	// reference 는 대부분 유효하므로 null check 필요 없습니다.
	// 아래 처럼 사용해도 안전합니다.
	r = 10;
}
f1(nullptr); // ok
f2(nullptr); // error

// 위와 같은 이유로 reference2.cpp 예제는
// "inc2 보다 inc3 이 좋은 함수 입니다."