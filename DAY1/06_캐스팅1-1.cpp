//06_casting1-1.cpp 

#include <iostream>

int main()
{
	int n = 3;

	// 아래 한줄에 대해서 생각해 보세요 ?
	// 안전할까요 ? 위험 할까요 ?
	double* p = (double*)&n;

	*p = 3.4;
}