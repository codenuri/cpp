// 1_namespace3.cpp - 9page 내용
// 
#include <algorithm>
using namespace std;

// 핵심 #1. C++ 표준의 모든 요소는 "std" 라는 이름 공간에 있습니다.

int count = 10;

int main()
{
	int n = min(3, 2); // C++ 표준 함수. algorithm 헤더 필요
//	int n = std::min(3, 2); 

	int k = count; // 왜 이코드가 에러일까요 ?
				   // 이유가 뭘까요 ?
}
