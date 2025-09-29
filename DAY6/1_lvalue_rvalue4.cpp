int main()
{
	const int c = 1;

	c = 1; 	// error.  c 는 lvalue ? rvalue ? => lvalue 
			// 상수 이므로 등호의 왼쪽에 올수 없는 것 
			// immutable lvalue

	// 모든 rvalue 는 상수이다 ? 맞다 ? 아니다 ?
	// => 상수가 아니다. 단지 rvalue 이므로 등호의 왼쪽에 올수 없는것 
}

// lvalue : 이름이 있고, 메모리를 사용한다.
//          주소연산자로 주소를 구할수 있다.

// rvalue : 임시로 만들어진 값, 
//          이름이 없고, 메모리를 지속적으로 사용하는 것은 아님.
//          상수라서 왼쪽에 못오는 것이 아니라, rvalue 라고 안되는 것. 