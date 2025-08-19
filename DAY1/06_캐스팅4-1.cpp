#include <iostream>

// const_cast : 

int main()
{
	const int c = 10;

	// 아래 코드는 상당히 위험한 캐스팅
	int* p1 = (int*)&c; // ok.  C 스타일의 캐스팅은 대부분 허용.. 위험
	int* p2 = static_cast<int*>(&c); // error. 너무 위험하다.
	int* p3 = reinterpret_cast<int*>(&c); // error. 이것은 허용안됨. 상수성 제거는.너무 위험 
	int* p4 = const_cast<int*>(&c); // ok. 상수성 제거를 위한 전용 캐스팅
	
	// 단, 캐스팅해서 주소를 p4에 보관했지만,  보관하는 정도로만 사용해야 합니다.
	// 아래 처럼 값을 변경하는 코드를 사용하면안됩니다.
	*p4 = 20; // 절대 금지. 
}

// 결론 
// C++의 캐스팅도 결국 위험한 캐스팅을 대부분 허용합니다.
// => 하지만 용도에 따라 캐스팅 방법을 다르게 사용하므로서
//    코드에 의도를 나타낼수 있습니다.
// => 보다 안전한 코드를 작성할수 있습니다.

// static_cast, reinterpret_cast, const_cast 
// dynamic_cast : 상속을 알아야 합니다. 상속관계에서만 사용 - 내일
