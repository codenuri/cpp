// 6_함수1.cpp  34 page ~
// C++함수의 특징 1. 디폴트 파라미터

// 인자를 전달하지 않은 경우 디폴트 값 사용

void foo(int a = 0, int b = 0, int c = 0)
{
}

int main()
{
	foo(1, 2, 3);
	foo(1, 2);		// foo(0, 1, 2)
	foo(1);			// foo(0, 0, 1)
	foo();			// foo(0, 0, 0)
}


