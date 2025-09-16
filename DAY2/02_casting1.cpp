#include <iostream>

int main()
{
	int n = 3;

//	double* p = &n; // error
	double* p = (double*)&n; // ok

	// 위 캐스팅이 성공했다면 아래 처럼사용가능합니다.
	// => 아래 코드 실행시 메모리 그림을 생각해 보세요
	*p = 3.4;

}
