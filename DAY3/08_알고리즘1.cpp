#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

int main()
{
	std::list<int>   s = { 1,2,3,4,5,6,7,8,9,10 };
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	// 컨테이너에서 3을 찾고 싶다.

	// 방법 #1. 멤버 함수 find 제공
	// 장점 : 사용하기 쉽다.
	// 단점 : 모든 컨테이너에 find 멤버 함수가 있어야 한다.
	s.find(3);
	v.find(3);
	

	// 방법 #2. find 를 멤버가 아닌 일반 함수(템플릿)으로 제공하자.
	// => 인자로 반복자를 받으면 동일한 방법으로 이동가능하다.
	// => 한개의 find 로 모든 컨테이너에 사용가능. 
	// 장점 : 하나의 find 로 모든 컨테이너(진짜 배열도 가능)에 적용가능
	// 단점 : 코드가 복잡해 보인다.
	std::find(s.begin(), s.end(), 3);
	std::find(v.begin(), v.end(), 3);
}
// 알고리즘
// 일반적인 의미 : 문제를 해결하는 방법
// C++에서의 의미 : find 같은 멤버가 아닌 일반함수 템플릿