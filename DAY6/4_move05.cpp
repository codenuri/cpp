// std::move()
#include <iostream>
#include <cstring>

class Cat
{
	char* name;
	int   age;
public:
	Cat(const char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
	~Cat() { delete[] name; }

	Cat(const Cat& c) : age{c.age}
	{
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);
		std::cout << "COPY" << std::endl;
	}
	// "move(이동)" 생성자
	// => temporary(rvalue) 를 위해서 만든것
	Cat(Cat&& c) : age{c.age}, name{c.name}
	{
		c.name = nullptr;
		std::cout << "MOVE" << std::endl;
	}
};
Cat foo()
{
	Cat c{"yaong", 3};

	return c;	// return Cat{c} <= 리턴용 temporary 생성
				// => 이 때도 복사 생성자 호출
				// => c라는 이름이 있는 객체로 "temporary" 만들기 때문에 "복사생성자가" 사용되야 하지만
				// => c가 파괴될것을 컴파일러가 알기때문에
				// => 복사가 아닌 move 생성자 호출
				// => 지역변수 반환으로 만드는 임시객체는 "이동생성자로 만들게 된다."
}
int main()
{
	Cat c1{"nabi", 2};

	Cat c2 = c1;	// COPY 호출

	Cat c3 = foo();	// MOVE 호출 => 이순간 2번의 호출

	Cat c4 = static_cast<Cat&&>(c2); // MOVE 호출
	Cat c5 = std::move(c3); // 내부적으로 위와 같은 캐스팅 수행
}

// 핵심 
// std::move() 가 자원을 이동하는 것 절대 아닙니다.!!
// 1. std::move(obj) 는 단지, obj 를 rvalue 로 캐스팅 할 뿐 입니다.
// 2. 캐스팅의 결과를 "복사 생성자"가 아닌 "이동생성자"를 호출하는 것입니다.
// 3. 즉, move 기능은 std::string 같은 클래스의 설계자가 move 생성자를 제공했기 때문에 가능한것. 

// C++ 창시자
// => std::move() 를 사용하면 개발자를 혼란스럽게 한다.
// => std::rvalue_cast 라는 이름으로 하자. 

// 혼자 학습할때 "결과가 생각대로 나오지 않는 경우가 많습니다."
// => 컴파일러가 "복사생성자 또는 move 생성자를 생략하는 현상 때문입니다."

// => 이부분 학습시 권장
// => visual studio 보다는 g++ 권장
// => g++ 소스이름.cpp -std=c++11 -fno-elide-constructors 권장

// -fno-elide-constructors : 복사생성자 또는 move 생성자를 생략하지 말라. 