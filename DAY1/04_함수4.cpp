// 39p ~
// C++ 함수의 특징 4. 함수 템플릿

/*
int square(int a)
{
	return a * a;
}
double square(double a)
{
	return a * a;
}
*/

// 구현이 유사(동일)한 함수가 여러개 필요하면
// 직접 함수를 만들지 말고, 
// 함수를 만드는 틀(template)을 만들면 됩니다.
template<typename T>
T square(T a)
{
	return a * a;
}
int main()
{
	// 방법#1. 템플릿의 타입 인자를 명시적으로 전달. 
	square<int>(3);		// 1. 이순간 컴파일러는 square(int a) 라는 함수를 생성
						// 2. 그리고 이위치는 call square<int>(3) 으로 변경

	square<double>(3.4); // 1. square(double a)  라는 함수를 생성
						 // 2. 이 위치는 call square<double>(3.4)
						 // 결국 기계어 코드에는 square 함수가 2개 있습니다.

	// 방법 #2. 타입인자 생략하면 함수인자로 타입을 추론
	square(3);    // 3을 보고 타입이 T = int 로 추론
	square(3.4);
}
// C++에서 템플릿은 너무 중요합니다.
// => 정확히 알아야 합니다
// => godbolt.org 에 접속해 보세요


// code bloat(코드 폭팔)
// => 템플릿 사용시, 컴파일러가 너무나 많은 함수(구조체, 클래스)등을 만들어서
//    코드 메모리가 증가하는 현상

// 사람이 만들면 정수 계열 타입은 square(int) 정도면 되는데..
// template 사용시 square(char),square(short),square(int) 가 생성되는 현상

// => 임베디드 분야에서 template 을 꺼리는 대표적인 이유