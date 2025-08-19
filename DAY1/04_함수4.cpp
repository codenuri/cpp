// 39p ~
// C++ 함수의 특징 4. 함수 템플릿

/*
int square(int a)
{
	return a * a;
}
double square(double a)
{
	return a * a;
}
*/

// 구현이 유사(동일)한 함수가 여러개 필요하면
// 직접 함수를 만들지 말고, 
// 함수를 만드는 틀(template)을 만들면 됩니다.
template<typename T>
T square(T a)
{
	return a * a;
}

int main()
{
	square(3);
	square(3.4);
}