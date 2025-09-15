// 28 page ~
// auto 

int main()
{
	int x[3] = { 1,2,3 };

//	int n = x[0];	

	// auto : 우변의 값으로 좌변의 타입을 결정해 달라는 것
	//		  컴파일 시간에 결정되므로 성능 저하는 없음
	//		  C++11 에서 도입. 
	auto n = x[0];	

	// auto 는 생각보다 어렵습니다.
	// 아래 코드에서 a의 타입은 ?
	const int c = 10;
	auto a = c; // 1. const int a = c;
				// 2. int a = c;
}
