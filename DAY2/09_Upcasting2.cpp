// 6_Upcasting1.cpp      140 page ~

class Animal
{
public:	int age;
};
class Dog : public Animal
{
public:	int color;
};
class Cat : public Animal
{
public:	int speed;
};

// upcasting 활용 #1. 동종을 처리하는 함수 만들기 
//void new_year(Dog* p)  // 인자로 Dog 객체만 받겠다는 의도
void new_year(Animal* p) // 인자로 모든 동물을 받겠다는 의도
{						 // 동종(동일 기반 클래스)을 처리하는 함수
	++(p->age);
}

int main()
{
	Dog d; new_year(&d);
	Cat c; new_year(&c);

	// upcasting 활용 #2. 동종을 보관하는 컬렉션(배열) 만들기
	Dog* cage1[10];     // Dog 객체만 보관 가능한 배열
	Animal* cage2[10];  // 모든 동물을 보관하는 배열
}
