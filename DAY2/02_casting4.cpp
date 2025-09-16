#include <iostream>

// reinterpret_cast 는 아래 2가지 용도에만 사용가능. 
// 1. 서로 다른 타입의 주소(reference) 변환
// 2. 정수 <=> 주소 사이의 변환

int main()
{	
	int n = 3;

	// int* => double* 로 변경
//	double* p1 = static_cast<double*>(&n); // error. 
	double* p1 = reinterpret_cast<double*>(&n); // ok

	// 정수 => 포인터 변환
//	int* p2 = 1000; // error
//	int* p2 = static_cast<int*>(1000); // error
	int* p2 = reinterpret_cast<int*>(1000); // ok
	
	// 위 2가지 용도이외의 작업은 할수 없습니다.
	int n1 = 3.4; // ok. 캐스팅 없어도 되는 작업이지만
	int n2 = reinterpret_cast<int>(3.4); // error. 용도에 맞는 작업 아님.
										 // 이작업을 하고 싶었다면 static_cast 사용
}

