// 인자로 auto 를 사용하는 경우 - C++20 부터
// => 별거 아닙니다. 그냥 template 을 간단하게 사용하는 표기법이 도입된것
void f1(auto n) 
{
}

// 위 코드와 아래 코드는 완전히 동일합니다.
// => 즉, 위 코드는 template 을 간단히 만들때 사용하는 것. 
template<typename T>
void f1(T n) 
{
}

int main()
{
	f1(10);		// void f1(int) 생성
	f1(2.2);	// void f1(double) 생성
}