// 함수 인자로
// int&  : 인자로 int 타입의 lvalue 만 받겠다는 의도. 
// int&& : 인자로 int 타입의 rvalue 만 받겠다는 의도. 
// T&    : 인자로 임의 타입의 lvalue 만 받겠다는 의도. 
//		   => T = int, int&, int&& 등의 모든 경우를 고려해도, 
//			  collapsing 규칙을 적용하면 결국 lvalue reference

// T&& : 임의 타입의 lvalue 와 rvalue 를 모두 받을수 있다.
// => 모두 받을수 있다는 것은, 각각을 받을수 있는 함수가 생성되는 것
// => 생성된 함수는 인자가 call by value 가 아닌, call by reference

// => 템플릿 만들때 인자로 T&& 를 사용하면 아래와 같은 특별한 추론 규칙이 적용됩니다.

// 인자로 rvalue(3) 을 전달 : T = int  	T&& = int&&      f4(int&&)
// 인자로 lvalue(n) 을 전달 : T = int&  T&& = int& &&    f4(int& )   

// C++11 초창기에 "T&&"의 이름이 없었습니다.
// 그래서, "effective modern C++" 책에서 "universal reference" 라는 이름을 제안
// 하지만, 추후 C++ 표준위원회는 "forwarding reference" 라고 부르기로 결정. 
// => forwarding 할때 사용하기 때문에. 



template<typename T> void f4(T&& a)
{
}

int main()
{
	int n = 3;
	f4(3);	
	f4(n);	
}