// 10 page 내용입니다.

//#include <stdio.h>  // C언어용 헤더. printf 등이 global 영역에만 있습니다.
#include <cstdio>     // C++언어가 다시 만든 헤더
					  // 모든 C 함수가 global 과 std:: 안에 모두 있습니다.

// C언어용 헤더     C++이 새롭게 만든헤더
// <xxxx.h>       <cxxxx>
// <stdio.h>  ==> <cstdio>
// <stdlib.h> ==> <cstdlib>
// <math.h>   ==> <cmath >
// <string.h> ==> <cstring>

// C++언어
// => 대부분의 C 언어용헤더 그대로 사용가능
// => 하지만, C++이 새롭게 만든 헤더 사용 권장

int main()
{
	// #1. 모든 C++ 표준은 std 이름 공간에 있습니다.
	// #2. printf 는 C 표준이지만, C++ 표준이기도 합니다.

	printf("hello\n"); // ok

	std::printf("hello\n"); // ??
}
