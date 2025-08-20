#include <iostream>


class Animal
{
public:	
	int age;
};
class Dog : public Animal
{
public:	
	int color;
};
int main()
{
	Animal  a;
	Dog     d;

	Animal* p = &a;

	// static_cast : 컴파일 시간 캐스팅 이라는 의미로 "static"
	//		         즉, 컴파일 시간에 캐스팅을 수행

	// 핵심 : 컴파일 시간에는 p 가 가리키는 곳이 어떤 타입의 객체인지 알수 없다.
	//		 따라서, 아래 코드는 무조건 성공합니다.
	//       현재 p가 가리키는 곳은 Animal 이 있지만
	//       컴파일러는 조사할 방법이 없으므로 "개발자만 믿고" 허용해 줍니다.
	//	     이때 반환된 포인터 사용하면 버그!!!
	//	     "static_cast" 는 p가 가리키는 것이 Dog 라는 확신이 있을때만 사용
//	Dog* pd = static_cast<Dog*>(p);

//	std::cout << pd << std::endl;


	// dynamic_cast : 실행시간 캐스팅
	//				  실행시간에 p가 가리키는 곳이 Dog 인지 조사후 캐스팅
	//				  Dog 가 아니라면 nullptr(0) 반환

	Dog* pd = dynamic_cast<Dog*>(p);

	std::cout << pd << std::endl;

}




