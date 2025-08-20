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
// 3. Student 에 생성자 추가해 보세요 <========== 이 부분이 핵심
// 4. main 에서 Student 객체 생성해 보세요

class Student : public People 
{
	int id;
public:
//	Student(int id) : id{id} {}	// Student(int id) : People{}, id{id} {} 로 변경되므로
								// 					  ^ 이 부분 때문에 컴파일 에러

	// 해결책
	// Student 제작자는 반드시 People 의 생성자 모양을 알고 있어야 합니다.
	// => 그래서 아래 처럼 "age" 인자를 받아서 기반 클래스의 생성자에 전달해야 합니다.
	// => 아래 코드가 "전형적인 관례" 입니다. 반드시 알아야 합니다. 
	Student(int age, int id) : People{age},  id{id} {}							
};

int main()
{
	People p{20};

	Student s{20, 1};
}






