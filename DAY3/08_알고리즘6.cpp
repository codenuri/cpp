#include <iostream>
#include <vector>
#include <array>
#include <algorithm> // 정렬, 검색 등의 일반 알고리즘
#include <numeric> 	 // 합등을 구하는 수치 알고리즘

// C++ 표준 알고리즘은 100 여개 있습니다.
// => 정렬, 검색, 순열, 부분합 등의 대부분 기능 제공
// => 임베디드에서도 거의 다 사용가능
// => 진짜 배열도 동작

int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };

	std::sort(arr, arr+10);

	int x[10];
	std::partial_sum(arr, arr+10, x);

	for (auto e : x)
		std::cout << e << ", "; 
}