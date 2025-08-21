#include <iostream>
#include <array> // 앞에서 만든 array 은 이미 C++ 표준에 있습니다.
				 // 핵심 원리는 앞의 코드와 동일 

int main()
{
	// std::array : 힙을 사용하지 않고, raw array 와 완벽히 동일한 메모리 구조
	//              안전하고 오버헤드가 없어서 임베디드 환경에서도 아주 널리 사용. 권장
	std::array<int, 5> arr = {1,2,3,4,5};

	std::cout << arr.size() << std::endl;

	// 특징
	int x1[3] = {1,2,3};
	int x2[3] = x1; // error. 배열은 초기화(대입) 안됨

	std::array<int, 3> y1 = {1,2,3};
	std::array<int, 3> y2 = y1; // ok

	// 유용한 멤버함수가 몇개 있습니다.
	// 단, 배열과 같은 특징이므로, 크기 변경, 추가/삭제 하는 함수는 없습니다.
//	arr.push(1); // error. stack에 있는 배열은 절대 크기 변경안됨.
}

