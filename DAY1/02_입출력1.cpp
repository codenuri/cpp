#include <cstdio>   // printf 사용 위해서 필요
#include <iostream> // std::cout, std::cin

// 13 page

int main()
{
	int n = 10;

	// C style 입출력
	printf("n = %d\n", n); // C style
	scanf("%d", &n);	   // 입력


	// C++ style
	// 특징 
	// 1. << 을 여러번 연속 사용가능
	// 2. 변수 출력시 "%d" 등의 format 지시어 필요 없음
	// 3. 개행은 std::endl  또는 '\n'

	// printf 정체    : 함수 입니다. 그래서 () 사용
	// std::cout 정체 : 객체 입니다. 강의 후반부에 구현원리 설명
	// 					std::endl 은 "함수" 입니다.
	// 참고. std::ostream 은 클래스
	//       std::endl 은 함수
	std::cout << "n = " << n << std::endl; // '\n'

	// C++ 스타일 입력 : std::cin 
	// >> 방향에 주의
	// &n 이 아닌 n 으로 전달. 
	std::cin >> n;
}
