#include <iostream>

// C++14 부터는 그냥 아래처럼만 해도 됩니다.
// => 이경우 리턴 타입을 생략한것
// => 컴파일러에게 return 문장을 보고 추론하라는 것
// 단점 : 2개이상의 return 문장이 있고, 서로 다른 타입으로 반환한다면 error
template<typename T1, typename T2>
auto add1(T1 a, T2 b)
{
//	if ( a == 0) return b;   // 이 코드가 있으면 에러 
	return a + b;
}

// 아래 코드는 사용자가 컴파일러에게 반환타입을 알려준것
//  무조건 "a+b"의  결과 타입으로 해달라
template<typename T1, typename T2>
auto add2(T1 a, T2 b) -> decltype(a + b) 
{
	if ( a == 0) return b; // 이 코드가 있어도.. 반환 타입은 "a+b" 의 결과로 추론..
							// 즉, 이코드는 에러 아님. 
	return a + b;
}


int main()
{ 
	std::cout << add(1.1, 2) << std::endl; 
	
}
