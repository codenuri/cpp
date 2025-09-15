#include <cstdio>
// 37 page ~
// 함수 오버로딩
// => 인자의 갯수나 타입이 다르면 동일이름의 함수를 여러개 만들수 있다.
// => C#, java 등의 대부분의 다른 언어도 지원

// 함수 오버로딩 문법이 없는 언어 : C 언어, Python 언어, Rust 언어

int square(int a)
{
	return a * a;
}

double square(double a)
{
	return a * a;
}

int main()
{
	square(3);
	square(3.4);
}
