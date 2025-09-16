// C++98 시절 스타일
template<typename T>
T square1(T a) 
{
	return a * a;
}

// C++20 부터는 대부분 아래 처럼 작성
auto square2(auto a) 
{
	return a * a;
}

int main()
{
	square1(3);
	square1(3.3);
	square2(3);
	square2(3.3);	
}