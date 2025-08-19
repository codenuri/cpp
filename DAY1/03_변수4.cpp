// 28 page ~
// auto 

int main()
{
	int x[3] = { 1,2,3 };

//	int n = x[0];

	// auto : 우변의 초기값으로 좌변의 타입을 결정해 달라.
	//		  컴파일러가 컴파일 시간에 결정.
	auto n = x[0]; // 컴파일 시에 "int n = x[0]" 로 변경

	// decltype : () 안의 표현식을 타입을 조사해서 사용
	// => 언제 사용하나요 ? "복잡한 템플릿에서.. "
	decltype(n) d;  // int d

	// auto 는 쉬워 보이지만 결코 쉽지만은 않습니다.
	const int c = 10;

	auto a1 = c; // 1) int a1 = c; 
				 // 2) const int a1 = c;
}
