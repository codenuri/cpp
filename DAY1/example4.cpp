#include <iostream>

// 아래 코드는 C++11 의 특징을 잘 나타내는 코드
// => 이 코드는 반환 타입을 정확히 표기 한것
// => 아래 코드는 return 문장이 여러개 있어도 에러 아님.
template<typename T1, typename T2>
auto Add1(T1 a, T2 b) -> decltype(a + b)
{
	if ( a == 0) return b;
	return a + b;
}
// C++14 부터는 auto 만 표기해도 됩니다.
// => 의미 : return 문장으로 부터 반환 타입을 추론해 달라.
// => 단점 : return 문장이 2개이상이고, 서로 다른 타입이라면 컴파일 에러
template<typename T1, typename T2>
auto Add2(T1 a, T2 b) 
{
	if ( a == 0) return b; // 이문장이 있으면 컴파일 에러
	return a + b;
}

int main()
{
	Add1(2.1, 2);
	Add2(2.1, 2);
}