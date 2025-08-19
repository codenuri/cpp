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
}