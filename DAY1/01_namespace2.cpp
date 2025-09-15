#include <stdio.h>
// namespace 에 있는 함수를 접근하는 3가지 방법 - 8 page

namespace Audio 
{
	void init() { printf("Audio init\n");	}
}

namespace Video 
{
	void init()	{ printf("Video init\n");	}
}

int main()
{
	// 1. 완전한 이름을 사용한 접근(qualified name)
	Audio::init();

	// 2. using declaration(선언) 을 사용
	using Audio::init;  // init 함수만 현재 영역에서 다시 선언
						// Audio 이름 없이 init 사용가능.
	init();	// Audio::init() 과 동일


	// 3. using directive(지시어) 사용
	using namespace Audio; // Audio 안의 모든 요소를 Audio 이름 없이 사용
	init();
//	draw(); // Audio::draw() 가 있다면.. 이렇게도 가능
}
