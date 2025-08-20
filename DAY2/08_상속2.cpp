// 5_상속2

// C++의 접근지정자는 총 3개 입니다.
// => private
// => protected
// => public

class Base
{
private:   	// 자신의 멤버 함수만 접근가능. 파생 클래스에서도 접근 안됨.
	int a;	

protected: 	// 자신의 멤버 함수와 파생클래스 멤버 함수 에서 접근 가능
	int b;	

public:    	// 모든 곳에서 접근 가능. main 에서도 가능. 
	int c;	
};

class Derived : public Base  
{
public:
	void foo()
	{
		a = 0;	// error. 기반 클래스의 private 은 파생 클래스도 안됨. 
				// 접근하고 싶었다면 기반 클래스가 제공하는 함수 다시 호출 set_a(0) 등
		b = 0;  // ok. protected 
		c = 0;  // ok. 모든 곳에서 접근 가능. 
	}
};
int main()
{
	Base base;
	base.a = 0; 
	base.b = 0; 
	base.c = 0; 
}
