// 클래스에 가상함수가 있다면
// 컴파일러는 아래와 같은 배열을 추가합니다
// 이 배열에 "타입정보 + 모든가상함수주소" 가보관 됩니다.
void* Base_vtable[] = { Base타입정보, &Base::f1, &Base::f2, &Base::f3};

class Base 
{
	void* vtptr = Base_vtable; // 컴파일러가 추가한 멤버 

	int a;
public:
	virtual void f1() {}
	virtual void f2() {}
	virtual void f3() {}
};
//---------------------
void* Derived_vtable[] = { Derived타입정보, &Base::f1, &Derived::f2, &Base::f3};

class Derived : public Base 
{
	void* vtptr = Derived_vtable; // 컴파일러가 추가한 멤버 

	int b;
public:
	virtual void f2() {}
};
int main()
{
	Base b1, b2;
	Derived d;

	Base* p = &d;

	p->f2();

	// 위 한줄을 컴파일러는 아래 의미의 코드로 변경합니다.
	// p->vtptr[2](); // f2가 2번째 가상함수이므로 2.
						// 즉, 순서가 중요합니다.
}

// 가상함수 사용시
// 1. 가상함수 테이블에 대한 오버헤드
//    => 클래스당 한개, 가상함수가 1000개 라면 1000* 포인터 크기

// 2. 객체당 한개의 포인터 추가


// 3. 호출시, 테이블에서 주소를 꺼내서 호출해야 하므로
// => 몇번의 메모리를 따라가게 됩니다
// => 호출시 성능저하.

// godbolt.org 에
// 가상함수2.cpp 넣으세요