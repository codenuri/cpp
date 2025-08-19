// 1_namespace3.cpp - 9page 내용
// 
#include <algorithm>
//using namespace std;

// 핵심 : C++의 모든 표준 함수는 "std" 라는 namespace 안에 있습니다.

int count = 0; // 사용자가 만든 전역변수

int main()
{
	int n = std::min(3, 2); // C++ 표준 함수. algorithm 헤더 필요
					   // std namespace 안에 있습니다.

	int ret = count; // 이 코드가 왜??? 에러 일까요 ???
					 // 어떤 문제가 있을까요 ??
					 // C++ 표준에 "std::count()" 라는 함수가 있습니다.
					 // 위에 using namespace std 때문에
					 // std 없이도 count() 사용 가능
					 // =>즉, 사용자의 변수 count 와
					 //       C++ 표준 count() 함수의 이름 충돌 발생


}
