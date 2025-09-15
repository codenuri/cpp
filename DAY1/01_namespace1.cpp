//  교재 6 page
#include <stdio.h>

// namespace 문법
// => 프로그램의 구성요소를 관련된 것끼리 논리적으로 분리하는 것.
// => 이름 충돌등을 막을수 있다.

namespace Audio 
{
	// Audio 관련 모든 요소를 이곳에 작성
	// 함수, 구조체, 전역변수, 상수
	void init() { printf("Audio init\n");	}
}

namespace Video 
{
	void init()	{ printf("Video init\n");	}
}

int main()
{
	Audio::init();
	Video::init();
}
