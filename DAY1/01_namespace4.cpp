// 10 page 내용입니다.

//#include <stdio.h>  // C언어용 헤더, printf 가 global 에만 존재 합니다.
#include <cstdio>     // C++언어용 헤더, printf 가 global 과 std 에 모두 존재

// C++ 언어
// => C 언어의 헤더를 그대로 사용해도 됩니다.
// => 그런데, C++에서 다시 만든 헤더 사용을 권장

// C 헤더		   C++ 헤더
// <xxx.h>	  =====> <cxxx>
// <stdio.h>  =====> <cstdio>
// <stdlib.h> =====> <cstdlib>
// <math.h>   =====> <cmath>
// <string.h> =====> <cstring>

int main()
{
	// C++ 언어 "C언어의 대부분" 을 포함 한다.
	// printf 는 "C 언어 표준" 이지만, "C++ 언어 표준 이기도 합니다."
	// => 그런데, C++의 모든 표준에 "std" 안에 있습니다.

	printf("hello\n"); // ok
	std::printf("hello\n"); // ??
}
