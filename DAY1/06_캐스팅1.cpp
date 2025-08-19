// 10_캐스팅1.cpp    49 page ~
#include <iostream>

// 변수의 주소를 다른 타입의 포인터로 캐스팅 하는 이유
// => 메모리 해석을 변경하겠다는 것

int main()
{
	int n = 0x11223344;

	// int주소를 char* 에 담는 것은 
	// => 4바이트 메모리를 1바이트 단위로 접근하겠다는것
//	char* p = &n; // error
	char* p = (char*)&n; // ok

	printf("%x\n", *p); // 44

}
