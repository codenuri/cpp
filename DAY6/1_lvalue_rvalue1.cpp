int main()
{
	int n = 1;

	n = 1; 	// ok.    n 은 등호의 왼쪽에 올수 있다 : lvalue
	1 = n;	// error. 1 은 등호의 왼쪽에 올수 없다 : rvalue  
}

// 핵심 : lvalue/rvalue 의 개념은 "변수(객체)"에 부여되는 개념이 아닙니다
// => 다음소스에서 정확히