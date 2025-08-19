// 3_변수5
// 30 page ~

// typedef int DWORD;
// typedef void(*PF)();

// C++11 부터는 using 이 더 편리합니다.
// 아래 2줄이 위 2줄과 동일. 
using DWORD = int;
using PF = void(*)();

int main()
{
	DWORD n;	// int n
	PF    f;	// 함수 포인터 f
}

