class Base 
{
	int a;
public:
	virtual void f1() {}
	virtual void f2() {}
	virtual void f3() {}
};

class Derived : public Base 
{
	int b;
public:	
	virtual void f2() {}
};

int main()
{
	Base b1, b2;
	Derived d1;

	Base* p = &d1;
	p->f2(); // 정확한 원리는 ?? 
			 // => 다음소스의 주석 참고
}