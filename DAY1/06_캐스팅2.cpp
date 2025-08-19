#include <iostream>

// C++은 "의도에 맞게" 사용하라고 4개의 캐스팅 연산자 제공
// 1. static_cast
// 2. reinterpret_cast
// 3. const_cast
// 4. dynamic_cast


// static_cast : 기본 캐스팅. 정상적인 프로그램은 이 캐스팅만 사용해야 한다.
// 		    논리적으로 맞고 위험하지 않은 경우만 허용
//          void*=> 다른 타입*,
//			상속관계의 캐스팅 등.
//          반드시 연관성이 있어야 한다


int main()
{
	double d = 3.4;
//	int    n = d;	// 캐스팅이 없어도 되지만 경고 나올수 있다.
	int    n = static_cast<int>(d); // 경고 제거 


	// void* => int* 로 변경
	// => 프로그램 작성시 반드시 필요한 작업
	// => 따라서, static_cast 로 가능
//	int* p1 = malloc(100);     // C언어 : ok. C++ : 에러
	int* p1 = static_cast<int*>( malloc(100) );  // ok


	// int* => double* 변경
	double* p2 = (double*)&n; // C 스타일 캐스팅은 가능
	double* p3 = static_cast<double*>(&n); // static_cast 는 안됨
										// 정말 필요하다면 
										// 이 일을 할수 있는 전용 캐스팅 사용


}

