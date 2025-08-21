#include <iostream>
#include <vector>

int main()
{
	// 배열   : 연속된 메모리에 데이타 보관. 단점 : 크기 변경 안됨. 모든 데이타가 스택에
	// vector : 연속된 메모리에 데이타 보관. 크기 변경도 가능      모든 데이타가 힙에 
	// => vector 를 프로그램에서 사용하면 아주  편리합니다.
	// => 그런데, 일부 임베디드 분야에서 힙사용을 엄격히 금지.
	// => vector, string, map, set, stack, queue 등을 모두 사용못함. 
	// => MISRA C++2008 : 거의 대부분의 C++ 표준 라이브러리(STL) 사용금지
	// => MISRA C++2023 : 힙을 사용안하는 일부 라이브러리, 대부분의 알고리즘, 반복자는 허용
	//    AUTOSAR C++17 : MISRA 보다는 관대.. 

	int x[5] = { 1,2,3,4,5 };

	std::vector<int> v = { 1,2,3,4,5 };

	std::cout << x[0] << std::endl; 
	std::cout << v[0] << std::endl; 

	v.resize(10);

	std::cout << v.size() << std::endl; // 10
}

