// 가상함수가 있다면 컴파일러가 아래 배열 추가

void* Base_vtable[] = { BASE_RTTI, &Base::f1, &Base::f2, &Base::f3};

class Base 
{
	void* vtable = Base_vtable; // 컴파일러가 추가
	int a;
public:
	virtual void f1() {}
	virtual void f2() {}
	virtual void f3() {}
};

//---------------------
void* Derived_vtable[] = { DERIVED_RTTI, &Base::f1, &Derived::f2, &Base::f3};

class Derived : public Base 
{	
	void* vtable = Derived_vtable;
	int b;
public:	
	virtual void f2() {}
};

int main()
{
	Base b1, b2;
	Derived d1;

	Base* p = &d1;
	p->f2(); 
}