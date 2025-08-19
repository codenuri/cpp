// 1_namespace3.cpp - 9page 내용
// 
#include <algorithm>
using namespace std;

// 핵심 : C++의 모든 표준 함수는 "std" 라는 namespace 안에 있습니다.

int count = 0; // 사용자가 만든 전역변수

int main()
{
	int n = min(3, 2); // C++ 표준 함수. algorithm 헤더 필요
					   // std namespace 안에 있습니다.

	int ret = count; // 이 코드가 왜??? 에러 일까요 ???
					 // 어떤 문제가 있을까요 ??
}
