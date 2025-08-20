// 3_정적멤버1 - 110 page
#include <iostream>

// 방법 #2. 전역변수 cnt 사용
// => 전역변수는 오직 한개만 존재하므로
// => 모든 Car 객체가 공유 한다.
// => 객체의 갯수 파악에 성공

// 그런데!!!
// => 전역변수는 어디서나 접근해서 변경가능한다.
// => 안전하지 않다.(MISRA 규칙에서 금지)

// => cnt 를 private 으로 보호 할수 없을까??
// ==> 다음 단계... 

int cnt = 0;

class Car
{
	int color;
	int speed;
public:


	Car()  { ++cnt; }
	~Car() { --cnt; }
};

int main()
{
	Car c1;
	Car c2;

//	cnt = -10;  // ok. error 가 아니다
				// 이제 객체의 갯수 파악은 실패

	std::cout << cnt << std::endl;
}

