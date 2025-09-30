// forwarding_reference
void f1(int&  r) {}
void f2(int&& r) {}

int n = 0;
f1(n);	// ok
f1(3);	// error

template<typename T> void f3(T& a)
{
}

// 함수 인자로
// int&  : 인자로 int 타입의 lvalue 만 받겠다는 의도. 
// int&& : 인자로 int 타입의 rvalue 만 받겠다는 의도. 
// T&    : 인자로 임의 타입의 lvalue 만 받겠다는 의도. 
//		   => T = int, int&, int&& 등의 모든 경우를 고려해도, 
//			  collapsing 규칙을 적용하면 결국 lvalue reference

// T&& : 핵심!!

template<typename T> void f4(T&& a)
{
}

int main()
{
	int n = 3;
	f4(3);
	f4(n);
}