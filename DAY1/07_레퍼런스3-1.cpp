// 함수 인자의 원본을 변경할수 없게 하려고 합니다.
// 다음중 좋은 코드는 ?
// => f1 이 좋은 코드!!

void f1(int n) 
{ 
	int k = n;
			// 이순간 복사본 n 에서 한번에 읽는 코드
}


void f2(const int& n) 
{ 
	int k = n;
			// 이 코드에서 n 은 결국 주소. 따라서
			// int k = (*n) 이므로 따라가서 값 꺼내기
			// 이소스를 "godbolt.org" 에 넣으세요
			// f1, f2의 어셈코드 비교
}

int main()
{
	int a = 10;
	f1(a);
	f2(a);
}