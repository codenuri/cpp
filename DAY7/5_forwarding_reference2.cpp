// 사전 지식. 
int main()
{
	int n = 10;

	int *p = &n;
	int* *pp = &p; // ok. 포인터를 가리키는 포인터는 만들수 있습니다.
					//    이중 포인터 

	int& r = n;
	int& &rr = r;	// error. 핵심 #1 : reference 를 가리키는 reference 는 만들수 없습니다.
					

	using LREF = int&; 
	using RREF = int&&;
	// 핵심 #2. reference to reference 를 개발자가 직접 코드로 만들수 없지만
	//			type alias 사용시 또는 타입 추론시에 발생되는 reference to reference 는 
	//          에러가 아니고, "reference collapsing" 규칙 으로 해석 됩니다.
	// reference collapsing
	LREF& r3 = n ;	// int&  &		=> int&
	RREF& r4 = n ;  // int&& &		=> int&
	LREF&& r5= n ;  // int&  &&		=> int& 
	RREF&& r6= 3 ;  // int&& && 	=> int&&
}

template<typename T> void foo(T a)
{
	T& r = a;	// int& & r = a
				// int& r = a
}

int n = 0;
foo<int&>(n);	// T = int& 로 결정




