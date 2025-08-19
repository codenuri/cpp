// 함수 인자의 원본을 변경할수 없게 하려고 합니다.
// 다음중 좋은 코드는 ?

void f1(int n) 
{ 
	int k = n;
}
void f2(const int& n) 
{ 
	int k = n;
}

int main()
{
	int a = 10;
	f1(a);
	f2(a);
}