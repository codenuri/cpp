// 가상함수 원리
// => 복잡한 내용이지만
// => 임베디드 개발자는 "필수"
// => "메모리 오버헤드를 알아야 합니다."

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
	Derived d;
	Base* p = &d;
	p->f2();
}
