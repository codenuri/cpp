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
	f4(3);	// 1. 3을 전달 하므로 T = int 로 추론. 인자는 T가 아닌 T&& => int&& 
			// 2. 생성된 함수는 f4(int&& a) 생성
			// 3. 결국, rvalue 만 전달 가능한데, 3은 rvalue 이므로 ok

	f4(n);	// 1. n은 int 타입 이므로 T = int, T&& = int&&
			// 2. 생성된 함수는 f4(int&& a) <= rvalue 만 전달 가능.
			// error. 

			// C++ 표준은 위처럼 하지 않고, 아래 처럼 추론합니다.
			// 그런데, 만약 n 은 int 지만, T = int& 로 추론했다면
			// T = int&, T&& = int& &&, f4(int&) 이므로
			// f4(n) 은 에러 아님. 
}