//#include <cstdio>   // printf() 사용시 필요
#include <iostream> // std::cout, std::cin 을 위한헤더, printf 도 사용가능

// 13 page

int main()
{
	int n = 10;

	// C style 입출력
	printf("n = %d\n", n); // C style

	scanf("%d", &n);	   // 입력

	// C++ style
	// 특징 : << 를 계속해서 사용가능
	//        %d 등의 format specifier 가 필요 없음
	// std::endl : 개행, '\n' 사용해도 됨
	
	// printf()  : 정체는 함수
	// std::cout : 정체는 객체, 지금은 사용법만, 마지막날 원리 설명
	std::cout << "n = " << n << std::endl; // C++ 스타일의 화면 출력
							// << '\n';    << 가능. 오히려 더빠름. 권장

	// 입력은 아래 처럼
	std::cin >> n;   // &n 이 아닌 n 
				     // << 가 아닌 >> 에 주의 
}
