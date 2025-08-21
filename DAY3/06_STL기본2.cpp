#include <iostream>

// 아래 구조체를 생각해 보세요

struct array 
{
	int buff[5];

	int size() const { return 5;}
}

int main()
{
	array arr = {1,2,3,4,5};

	std::cout << arr.size() << std::endl;
}

