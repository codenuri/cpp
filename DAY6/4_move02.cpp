#include <iostream>
#include <string>
#include <vector>

// move 장점

// 아래 코드는 "복사"에 의한 swap 입니다.
// => 느립니다. C++98 시절 코드
template<typename T>
void Swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

// 아래 코드는 "이동(move)" 에의한 swap
// => 아주 빠릅니다. C++11 이후 코드. 
template<typename T>
void Swap(T& a, T& b)
{
	T tmp = std::move(a);
	a = std::move(b);
	b = std::move(tmp);
}
int main()
{
	std::string s1 = "hello";
	std::string s2 = "world";
	Swap(s1, s2);
}
// C++ 개발자가 move 를 통해서 알아야 하는것
// 1. std::swap() 등의 알고리즘 사용시 std::move()를 사용하면 빨라진다는 것
// => 어렵지 않은 내용, 아주 널리 사용..

// 2. std::string 이 아닌 사용자가 만든 타입(Character class등) 도 move 를 지원하려면
//    어떻게 해야 하는가 ?
// => 약간 까다로운 주제..


