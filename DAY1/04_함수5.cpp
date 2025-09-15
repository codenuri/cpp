// 04_함수5.cpp

// C++98 시절의 함수 모양
/*
int square(int a)
{
	return a * a;
}
*/
// C++11 에서 새롭게 등장한 함수 모양
// => suffix return type 이라는 문법
// => swift, rust, python의 type annotation 이 모두 이방식으로 표기
auto square(int a) -> int
{
	return a * a;
}

int main()
{

}