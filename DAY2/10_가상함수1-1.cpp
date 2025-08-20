// 7_가상함수1  143 page ~
#include <iostream>
// 중요한 문법
// => 예전에는 임베디드 분야에서 사용하지 말라고 했었는데..
// => 요즘은 "정확한 원리를 알고 사용해라" 권장. 

class Animal
{
public:
	// non-virtual : C++ 기본 바인딩인 static binding 해달라는 것.
	//				 컴파일 시간에 포인터 타입으로 호출
	void Cry1() { std::cout << "Animal Cry1" << std::endl; } 


	// virtual function : dynamic binding 해달라는 것
	//					  실행할때 메모리 조사후 호출 해달라. 
	virtual void Cry2() { std::cout << "Animal Cry2" << std::endl; } 
};

class Dog : public Animal
{
public:
	        void Cry1() { std::cout << "Dog Cry1" << std::endl; }  
	virtual void Cry2() { std::cout << "Dog Cry2" << std::endl; }  
};

int main()
{
	Animal a; 
	Dog    d; 

	Animal* p = &d; 	

	p->Cry1();	// non-virtual. static binding. 컴파일시 포인터 타입으로 함수 결정
	p->Cry2();	// virtual,     dynamic binding 실행시 메모리 조사후 함수 결정.
}

