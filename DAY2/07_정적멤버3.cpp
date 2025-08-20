// 3_정적멤버1 - 110 page
#include <iostream>

// 방법 #3. 



class Car
{
	int color;
	int speed;
public:
//	int cnt = 0;		// 멤버 데이타 : 객체당 한개씩 생성

	static int cnt;		// static 멤버 데이타 : 오직 한개만 생성, 모든 객체가 공유


	Car()  { ++cnt; }
	~Car() { --cnt; }
};
// static 멤버 데이타는 반드시 클래스 외부 선언 필요합니다.
// => 초기화도 이 위치 에서.. 
int Car::cnt = 0;

int main()
{
	// Car::cnt 는 객체가 없어도 메모리에 있으므로
	// 객체 만들기 전에도 사용가능합니다.
	std::cout << Car::cnt << std::endl;

	Car c1;
	Car c2;

	std::cout << Car::cnt << std::endl;
}

// static 멤버 데이타 특징
// 1. 객체를 만들지 않아도 main 함수 시작전에 이미 메모리에 존재 (전역변수와 동일)
// 2. 객체 생성시 객체의 메모리에는 놓이지 않음
// 3. "클래스이름::이름" 으로 접근