#include <cstdio>

// RAII 기술

// 자원을 관리할때는 "생성자/소멸자" 에 의존해야 한다.

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
}

int main()
{

}