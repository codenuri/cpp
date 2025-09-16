#include <iostream>

// C++ 언어는 안전한 캐스팅을 위해서 
// 4개의 캐스팅 연산자 제공

// 1. static_cast
// 2. reinterpret_cast
// 3. const_cast
// 4. dynamic_cast

// static_cast : 가장 기본 캐스팅, 안전한 코드를 위해서는 이 캐스팅만 사용 권장.
// 			논리적으로 맞고 위험하지 않은 경우만 허용
//			1. 기본 타입의 값 캐스팅
//          2. void*=> 다른 타입*,
//			3. 상속관계의 캐스팅 등.
//          4. 반드시 연관성이 있어야 한다


int main()
{
	double d = 3.4;
	int    n1 = d; // double => int 변환. 캐스팅 없어도 되지만, 경고 발생할수 있음. 

	int    n2 = static_cast<int>(d); // 의도적인 코드이므로 경고 내지 말라는 것

	// void* => 다른 타입* 로 캐스팅
	// => 이 작업은 일반적으로 필요한 작업이다.!!! 반드시 필요 하다.
	int* p1 = malloc(100);   // error. 
	int* p2 = (int*)malloc(100);  // C 스타일 캐스팅은 대부분 성공
	int* p3 = static_cast<int*>(malloc(100));  // ok. 

	// void* 아닌 서로 다른 타입의 주소 변환은 모두 위험하다.
	// static_cast 는 허용안함
	double* p4 = static_cast<double*>(&n1); // error
}

