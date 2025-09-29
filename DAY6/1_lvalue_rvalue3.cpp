int x = 0;
int  f1() { return x;} // x 가 아닌 x의 값인 "0" 반환
int& f2() { return x;} // "0" 이 아닌 x의 별명 반환"

// rvalue 의 특징
int main()
{
	int n = 1;

	// #1. 등호의 왼쪽에 올수 없다.
	(n = 2) = 1;	// ok. n = 2 는 의 최종결과는 n, lvalue
	(n + 2) = 1;	// error. n+2 는 임시값 3.    n+2 는 rvalue

	// #2. rvalue 는 주소를 구할수 없다.
	int* p1 = &(n = 2); // ok. 결국 &n
	int* p2 = &(n + 2); // error.  임시값은 & 연산자로 주소를 구할수 없다.

	// #3.	
	f1() = 1; // "0 = 1". error.      값은 반환하는 함수는 rvalue
	f2() = 1; // "x의 별명 = 1". ok    참조를 반환하는 함수는 lvalue 
}