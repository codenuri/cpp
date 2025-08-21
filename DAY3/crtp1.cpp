#include <iostream>

// RS232 통신 프로그램을 C++로 설계해 봅시다.

int open() { return 100}

void write() {}

bool recv(int handle, int* buff, int size) 
{
	// RS232 통신을 통해서 데이타 수신

	return false; // 성공시 true, 실패시 false
}

int main()
{
	int handle = open();
	char buff[256];
	recv(handle, buff, 256);
}