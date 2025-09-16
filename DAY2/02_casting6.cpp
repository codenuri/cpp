int main()
{
	const int c = 10;

	// c의 주소를 double* 에 담고 싶습니다.
	double* p1 = (double*)&c; // ok. C 스타일 캐스팅은 아주 강력!!

	// 위 코드를 C++ 캐스팅으로 해보세요

//	double* p2 = static_cast<double*>(&c); // error
//	double* p2 = reinterpret_cast<double*>(&c); // error. const 제거 못함
//	double* p2 = const_cast<double*>(&c); 	// error. const 제거 가능하지만
											// 같은 타입의 상수성만 제거, 
											// 현재 코드는 다른 타입

	double* p2 = reinterpret_cast<double*>( const_cast<int*>(&c) );
				// const int* => int* 
				// int* => double*
	// 숙제 : 위 코드를 const_cast( reinterpret_cast ) 형태로 변경해 보세요. 

	// 위 코드는 "실전에서는 자주 등장하지는 않지만"
	// 학습을 위한 코드
	// => 그런데, 오픈소스에서 가끔 볼수는 있습니다.
}





