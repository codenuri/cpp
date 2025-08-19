int main()
{
	const int c = 10;

	// c의 주소를 double* 에 담고 싶습니다.
	double* p = (double*)&c; // C 캐스팅은 한번에 가능... !!!!


	// 위코드를 C++ 캐스팅으로 해보세요
//	double* p1 = reinterpret_cast<double*>(&c); // error. const 제거 안됨
//	double* p1 = const_cast<double*>(&c);       // error. const 제거 가능하지만
												// 같은 타입의 상수성 제거만 가능

	double* p1 = reinterpret_cast<double*>(const_cast<int*>(&c));
					// const int* => int* 로 변환후 다시
					// int* => double* 로 변환

}

// 복습할때 
// 구글에서 "misra C++ casting" 검색후 1번째 링크

// misra C++ : 임베디드 환경에서 C++ 언어를 안전하게 사용하기 위한 규칙들 모음




