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
// p->f2();
// => p 가 가리키는 곳을 조사후 ===> 어떻게 조사????
// => 해당하는 f2() 호출       ===> 어떻게 호출 ??? f2 주소가 필요한다.

