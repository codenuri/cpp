// 2_메모리할당 - 47 page
#include <iostream>

int main()
{
	// C 스타일
	int* p = (int*)malloc(sizeof(int) * 20);
	free(p);

	// C++ 스타일
	int* p1 = new int;
	delete p1;

	int* p2 = new int[10];
	delete[] p2;
}

