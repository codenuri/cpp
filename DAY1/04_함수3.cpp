// 39p ~
// C++ 함수의 특징 3. 함수 템플릿

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
// 함수의 구현이 동일(유사)하다면 함수를 만들지 말고
// 함수를 만드는 "틀(template)" 을 만드는 것이 좋습니다.
template<typename T> 
T square(T a)
{
	return a * a;
}

int main()
{
	// 함수 템플릿 사용#1. 타입 인자를 전달
	square<int>(3);		// 1. 틀을 사용해서 "int square(int)" 함수를 생성	
						// 2. 이 코드에는 "call square(int)" 의미의 기계어 코드 생성

	square<double>(3.4);// 1. 틀을 사용해서 "double square(double)" 함수를 생성	
						// 2. 이 코드에는 "call square(double)" 의미의 기계어 코드 생성

	// 함수 템플릿 사용 #2. 타입 인자 생략
	// => 함수 인자를 가지고 컴파일러가 타입 추론
	square(3);		// 3은 int 이므로 T=int 로 결정됨
	square(3.4);
}

// template 을 정확히 이해 하려면 
// godbolt.org 에 접속하세요
// C++ 선택후, 위코드 넣으세요