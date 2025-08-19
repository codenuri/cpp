//  교재 6 page

// 빌드해 보려면
// 1. 명령 프롬프트 또는 vscode 터미널 실행
// 2. g++ 소스이름.cpp => a.exe 생성
// 3. a.exe 실행

// 위 과정을 편하게 하기 위해
// DAY1 폴더에 run.bat 있습니다.
// => run 소스이름.cpp

#include <stdio.h>

// namespace 문법 : 프로그래밍 구성요소를 관련있는 것을 모아서 논리적으로 분리
//                  이름 충돌등을 막을수 있다.
namespace Audio 
{
	// Audio 관련 모든 코드는 이곳에 작성
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
