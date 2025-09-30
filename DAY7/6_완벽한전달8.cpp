#include <iostream>
#include <string>
#include <functional>

int& f3(int& a, double d, const std::string& s ) 
{ 
	return a;
}

// 반환 타입도 돌려 주려면
// => decltype(auto) 반환 하세요
// => 복습시, auto 추론 규칙 학습해 보세요
// => 아래 코드에서 "decltype(auto)" 대신 "auto" 표기시 어떤 차이가 있는지 연구해 보세요

// 멤버 함수 호출시는 () 가 아닌. (객체.*포인터)() 가 되어야 합니다.
// => 멤버 함수도 성능 측정가능하게 하려면 std::invoke()로 
template<typename F, typename ... T>
decltype(auto) chronometry(F&& f, T&& ... arg)	
{
//	return f( std::forward<T>(arg)... );   
	return std::invoke( std::forward<F>(f), std::forward<T>(arg)...);

}

int main()
{
	int n = 0;

	int& ret = chronometry(f3, n, 3.4, "hello"); // f3(n, 3.4, "hello")	
}
