// 2_메모리할당 - 47 page
#include <iostream>
#include <cstdlib>
int main()
{
	// C 스타일
	int* p = (int*)malloc(sizeof(int) * 20);
	free(p);

	// C++ 스타일
	int* p1 = new int;
	delete p1;

	int* p2 = new int[10];	// 배열 할당의 경우는
	delete[] p2;			// 반드시 배열 delete 로 해야 합니다.
//	delete p2;		<== 절대 이렇게 하면 안됩니다.
}

// 					malloc			   		new
// 정체				함수					키워드
// 인자			    크기		    		타입
// 반환타입          void*					인자로 전달한 타입의 포인터
//				    대부분 캐스팅후사용		 캐스팅 필요없음
// 결정적 차이	     생성자 호출안됨          생성자 호출   <=== 내일.. 

// 단, 일부 임베디드 환경에서는
// => "동적 메모리 할당" 자체를 금지하기도 합니다.