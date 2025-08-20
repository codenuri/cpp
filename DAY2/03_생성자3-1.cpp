#include <cstdio>

// RAII 기술
// 자원을 관리할때는 "생성자/소멸자" 에 의존해야 한다.
// => C++ 에서 RAII 라는 이름을 가진 기술
// => 임베디드 분야에서는 아주 중시하고, Rust 언어는 모든것이 RAII. 즉, 자원의 수동 관리는 불가능

// Resource Acquision Is Initialization 의 약자
// (자원이 획득되는 것은 (자원관리객체)가 초기화 될때 이다.) 라는 의미

// => 해지가 아닌 획득에 중점을 두고 만든 용어.

// 참고
// 1. C++ 문법을 공부하세요
// 2. C++ 업계에서 관례적으로 사용되는 코딩 스타일을 익히세요
// => C++ Idioms 라고 부릅니다.
// => 구글에서 "C++ IDioms" 검색 1번째링크
// => "해당 기술이 임베디드 분야에서 허용되는지 확인(MISRA-C++2023, Autosar C++확인)"



class File 
{
	FILE* handle = 0;
public:
	File(const char* name, const char* mode)
	{
		handle = fopen(name, mode);
	}
	~File() { flose(handle);} // <== 이부분이 핵심!!
	
	FILE* get() const { return handle;}
};

void foo()
{
	File f("a.txt", "wt");

	// fwrite(f.get(), ...);

	// 별도의 자원해지가 없어도 f 소멸자에서 자동으로 자원 해지

	// 아래 같은 코드가 있어도 안전. f 의 소멸자는 호출됨.
	if ( 1 ) return ; // 이순간 함수가 바로 종료되지만, f 소멸자는 호출됨. 따라서 자원해지. 
}

int main()
{

}