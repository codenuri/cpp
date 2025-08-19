// 04_함수5.cpp

// C++98 스타일의 함수
int square1(int a)
{
	return a * a;
}

// C++11 에서 추가된 새로운 스타일의 함수
// => 핵심 : 반환 타입을 뒤에 표기.
// => suffix return type 이라는 문법
// => 아래 코드는 위와 동일
auto square2(int a) -> int
{
	return a * a;
}

int main()
{

}