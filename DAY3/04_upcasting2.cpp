#include <iostream>

class Animal
{
public:	
	int age;

	virtual ~Animal(){} // 가상 소멸자 - 내일 자세히 배우게 됩니다.
						// 이제 가상함수가 있으므로 "가상함수 테이블이 만들어지고"
						// 타입정보가 메모리에 놓이므로 
						// dynamic_cast 사용가능. 
};
class Dog : public Animal
{
public:	
	int color;
};

int main()
{
	Animal a;
	Dog d;

	Animal* p = &a;

	// #1. static_cast : 컴파일 시간 캐스팅.
	// => 1. 컴파일러는 컴파일 시간에는 p가 가리키는 곳에 어떤 객체가 있는지 알수 없습니다.
	//       (실행시 변경될수도 있으므로)

	// => 2. 따라서 static_cast 는 p가 가리키는 곳에 Dog가 있는지 조사할수는 없습니다.
	// => 3. 그래서 아래 코드는 항상 성공하고 주소가 나옵니다.
	// => 4. 즉, 아래 코드는 개발자가 책임지겠다는 의미 
	// => 하지만 지금은 p가 가리키는 곳이 Dog가 아니므로 
	//    pd->color = 10 같은 코드를 만들면 버그

	Dog* pd = static_cast<Dog*>(p);

	std::cout << pd << std::endl;


	// #2. dynamic_cast : 실행시간 캐스팅
	// => 실행시간에 p가 가리키는 곳을 조사해서 Dog 일때만 주소 반환
	// => Dog가 아니라면 0 반환
	// => 실행시간이므로 "약간의 오버헤드" 있습니다.
	// => 단, "타입정보"를 가상함수 테이블에 보관하므로
	//    "가상함수가 한개 이상 있는 클래스만 사용가능 "

	Dog* pd2 = dynamic_cast<Dog*>(p);

	std::cout << pd2 << std::endl;
}

// dynamic_cast
// => 처음 알게 되면 아주 좋아하고 많이 사용하려고 합니다.!!!
// => 그런데, dynamic_cast를 많이 사용하는 것은 나쁜 코드(디자인) 입니다.
// => 내일의 주제.!




