// 1_namespace3.cpp - 9page 내용
// 
#include <algorithm>
//using namespace std;

// 핵심 #1. C++ 표준의 모든 요소는 "std" 라는 이름 공간에 있습니다.
// 핵심 #2. using namespace std 를 사용시, 아래 코드에서 count 가 이름 충돌 나오는 현상
//         을 정확히 이해 하세요.

int count = 10;

int main()
{
//	int n = min(3, 2); // C++ 표준 함수. algorithm 헤더 필요
	int n = std::min(3, 2); 

	int k = count; // 왜 이코드가 에러일까요 ?
				   // 이유가 뭘까요 ?
				   // => C++ 표준에 "std::count()" 라는 함수 가 있습니다.
				   // => 그런데, "using namespace std" 때문에 std 없이 접근가능하고
				   // => 따라서, 전역변수 count 와 이름 충돌 발생
}
