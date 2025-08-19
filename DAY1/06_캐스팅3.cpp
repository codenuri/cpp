#include <iostream>

// reinterpret_cast 
// 1. 서로 다른 타입끼리의 주소 변환
// 2. 정수<=> 포인터 같은 변환  
// 만 가능
int main()
{
	double d = 3.4;
	int    n =  d; 

//	double* p = static_cast<double*>(&n); // error
	double* p = reinterpret_cast<double*>(&n); // ok
	
	int* p2 = 1000; // error. 정수 => 포인터 변환 안됨
	int* p3 = static_cast<int*>(1000); // error. 용도에 맞지 않음
	int* p4 = reinterpret_cast<int*>(1000); // ok. 이 용도에 사용하는 캐스팅

	// reinterpret_cast 는 위 2가지 위에 다른 용도로 사용안됩니다.
	int n2 = reinterpret_cast<int>(3.4); // error. 캐스팅이 없어도 되는것이지만
										// reinterpret_cast 사용시는 에러 
}

