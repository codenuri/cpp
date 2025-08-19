// 3_변수5
// 30 page ~

// typedef int DWORD;
// typedef void(*PF)();

// C++11 부터는 using 이 더 편리합니다.
// 아래 2줄이 위 2줄과 동일. 
using DWORD = int;
using PF = void(*)();

// typedef : 타입에 대한 별명만 가능
// using   : 타입에 대한 별명 + 템플릿에 대한 별명도 가능 

int main()
{
	DWORD n;	// int n
	PF    f;	// 함수 포인터 f
}

