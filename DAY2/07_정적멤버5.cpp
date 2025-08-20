class Car
{
	int color;
	static int cnt;
public:
	// 다음중 에러를 모두 골라 보세요
	// 핵심 1. static 멤버 데이타는 cnt 는 객체가 없어도 메모리에 있다.
	//     2. static 멤버 함수 goo 는 객체없이 호출 가능. 

	// foo() 를 호출한다는 것은 객체를 생성했다는 의미
	// => c.foo()
	// => 따라서, c 안에는 color 가 이미 있다.
	void foo()	
	{
		color = 0;	// 1. ok
		cnt = 0;	// 2. ok
		goo();		// 3. ok
	}
	static void goo()	
	{
		color = 0;	// 4. error
		cnt = 0;	// 5. ok
		foo();		// 6. error
	}
};
int Car::cnt;

int main()
{
	Car::goo(); // 객체없이 호출
}
// 핵심 
// => static 멤버 함수 에서는 static 멤버(데이타, 함수) 만 접근 가능하다. 