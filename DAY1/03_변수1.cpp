// 3_변수1
#include <iostream>

// 변수 : 모든 프로그래밍 언어에 있는 개념. 

// C++ 은 C언어의 변수 관련 문법을 더욱 발전시켰습니다.
// 교재 22 page ~

struct Point 
{
	int x = 0; // C++11 부터 구조체 항목에 초기값 지정 가능
	int y = 0; 
};

int main()
{
	bool b = true;   // 참/거짓을 나타내는 타입. 
	long long n = 0; // 64bit 정수 타입

	int n1 = 0b1;	 // C++14 부터 2진수 표기법도 가능
	int n2 = 1'000'000; // 큰숫자의 경우 자릿수 표기하면 가독성이 좋습니다.
						// 단순히 읽기 좋게 하기 위한것.
						// 특별한 의미는 없습니다.
	
	struct Point p1;    // C언어는 struct 변수 만들때 struct 필요
	Point p2; 			// C++은 struct 필요 없음.
}
