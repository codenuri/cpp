// 44page~
#include <iostream>

int main()
{
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };

	// C 언어의 전통적인 for 
	for (int i = 0; i < 10; i++)
	{
		std::cout << x[i] << std::endl;
	}

	// C++11 에서 추가된 새로운 for 문(range-for)
	// 파이썬 : for e in x
	// C#    : foreach e in x
	// 
	for( int e : x )
	{
		std::cout << e << std::endl;
	}

	// 전체가 아닌 5개만 할수 있나요 ?
	// 1칸이 아닌 2칸씩 이동되나요 ?
	// 거꾸로 할수 없나요 ?
	// => 모두 C++20 부터 가능합니다.
	// => 그전에는 "C style for" 문 사용하세요. 
}
