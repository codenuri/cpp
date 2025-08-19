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
