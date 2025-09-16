// 아래 f1, f2 는 약간의 차이가 있습니다.

// f1 : 반환타입은 인자 타입과 같다.
template<typename T>
T f1(T a)
{
	return 0;
}

// 인자 타입 : 호출하는 함수 인자로 결정
// 반환 타입 : return 문장으로 결정
auto f2(auto a)
{
	return 0;
}

int main()
{
	f1(3.4);	// double f1(double a) 함수 생성
	f2(3.4);	// int    f2(double a) 함수 생성
}