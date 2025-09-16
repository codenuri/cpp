// const_cast : 동일타입 변수의 "상수성을 제거" 하는 캐스팅

int main()
{
	const int c = 10;

	// const int* => int* 즉, const 제거
	int* p1 = &c;       // error
	int* p2 = (int*)&c; // ok.  C 캐스팅은 거의 성공.. 아주 강력
//	int* p3 = static_cast<int*>(&c); // error. 아주 위험한 작업
//	int* p3 = reinterpret_cast<int*>(&c); // error. 아주 위험하다. 
										  // 전용 캐스팅을 사용하라

	int* p3 = const_cast<int*>(&c); // ok. 

}
// 결론
// C++ 코드에서 캐스팅이 필요하면
// => C 스타일 캐스팅은 금지.
// => 기본적으로 static_cast 로 하세요
// => 혹시 에러가 발생하면, 용도에 따라 아래 2개중에서 용도에 맞게 고르세요
// 1. reinterpret_cast
// 2. const_cast

// 대부분 위 3개로 해결됩니다.
// 그래도 에러가 발생하면, "코드 자체가 논리적으로 잘못된것"

// dynamic_cast 는 "상속에 관련된것. 내일 배우게 됩니다."