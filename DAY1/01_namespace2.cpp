#include <stdio.h>

namespace Audio 
{
	void init() { printf("Audio init\n");	}
}

int main()
{
	// namespace 안의 요소에 접근하는 3가지 방법

	// #1. 완전한 이름.(Qualified name)
	Audio::init();

	// #2. using declaration(선언) 사용
	using Audio::init;  // Audio::init 은 Audio 없이 사용가능
	init(); 

	// #3. using directive(지시어)
	using namespace Audio; // Audio 안의 모든 요소를 Audio 이름 없이 사용가능
	init();

	// #2, #3 사용시 다시 이름 충돌 가능성있습니다
	// 아래 같이 했는데, 각각 init 이 있었다면 
	using namespace Audio;
	using namespace Video;  
//	init(); // 이름 충돌!!
}
