#include <iostream>

// 코딩 관례
// => class 설계시, 생성자를 만들어서
// => 모든 멤버 데이타를 초기화 하는 것이 좋습니다.
class People
{
	int age;
public:
	People(int age) : age{age} {   }
};
// 1. People 로 부터 상속받은 Student 를 만들어 보세요
// 2. Student 에 int id 멤버 데이타 추가해 보세요
// 3. Student 에 생성자 추가해 보세요
// 4. main 에서 Student 객체 생성해 보세요


int main()
{
	People p{20};
}






