#include <iostream>
// 24page - 중요한 변화.!

struct Point
{
	int x, y;
};
int main()
{
	// 기존 초기화의 문제점
	// => 변수에 종류에 따라 초기화 방법이 다르다. 
	int n1 = 10;
	int x1[3] = { 1,2,3 };
	Point p1 = { 1,2 };

	// C++11 부터 모든 종류의 변수는 {}로 초기화 가능
	// => "uniform initialization(일관된 초기화)" 라는 문법
	int n2 = {10};
	int x2[3] = { 1,2,3 };
	Point p2 = { 1,2 };

	// = 이 없어도 됩니다.
	int n3   {10};
	int x3[3]{ 1,2,3 };
	Point p3 { 1,2 };	

	// = 있는 초기화 : copy   initialization
	// = 없는 초기화 : direct initialization
	//    => 약간의 차이가 있는데, 현재 위 코드는 동일, 
	//    => 사용자 정의 타입(class)일때만 차이 있음. 
	// ------------------------------------------
	// prevent narrow

	int n4 = 3.4; // 실수 => 정수 변수에 넣기. 데이타 손실 발생. 
				  // C/C++ 은 가능. 하지만 대부분의 언어는 에러.!

	char c1 = 300; // 에러는 아니지만 overflow 발생!!

	int  n5 = {3.4}; // error. 데이타 손실이 있으면 에러
	char c2 = {300}; // error. overflow 가 있어도 에러
	char c3 {300};   // 역시 error.
	
	// 결론 : 안전한 프로그램을 원한다면 {} 초기화를 사용하세요. 
	// MISRA-C++, autosar C++ : 안전한 코드를 위한 규칙을 정리 한것 

}



