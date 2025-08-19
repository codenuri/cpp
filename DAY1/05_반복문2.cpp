// 44page~
#include <iostream>
#include <ranges>  // C++20 부터 제공되는 헤더

int main()
{
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };

//	for( int e : std::views::take(x, 5) ) // 5개만
//	for( int e : std::views::reverse(x) ) // 거꾸로
	for( int e : std::views::reverse( std::views::take(x, 5) )) // 5개만 거꾸로
	{
		std::cout << e << std::endl;
	}

}
