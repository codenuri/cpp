// C++ 함수 특징 3. inline   .. 36page


       int add1(int a, int b) { return a + b; }
inline int add2(int a, int b) { return a + b; }

int main()
{
	int n1 = add1(1, 2);  // 호출
						  // 1. 인자 2개를 약속된 장소에 넣고(32bit 스택, 64bit 레지스터)
						  // 2. add1 으로 이동(call add1)

	int n2 = add2(1, 2);  // 치환
						  // add2의 기계어 코드를 이위치에 놓아 달라.
						  // 장점 : 호출보다 빠릅니다.
}
// 이런 내용도 "정말 정확히 알고 싶다면(확인하고 싶다면)"
// => godbolt.org 에 위 코드 넣으세요

// 참고
// => inline 이라고 표기해도
// => 컴파일러 최적화 등을 할때만 적용됩니다.

// 확인하려면
// godbolt.org 에서
// msvc 컴파일러(마이크로 소프트 제공)선택후
// -Ob1 옵션으로 하면 치환 결과 확인 가능합니다.

