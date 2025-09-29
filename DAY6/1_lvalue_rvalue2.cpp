// lvalue, rvalue 개념
// => 변수가 아닌 "expression(표현식) 에 부여되는 개념"

// expression : 하나의 값을 만드는 코드 집합

// exression 이 만드는 하나의 값 : result

// result 의 2가지 속성(property) 
// => 1. type
// => 2. value category (등호의 왼쪽에 올수 있는가 ?)

int main()
{
	int n = 1;

	(n + 2) * 3; 	// result : 9
					// => type: int
					// => value category : rvalue
					//	   "9는 사용자가 할당한 메모리가 아닌 연산의 결과로 만들어진 임시값"
					//     "주로 메모리에 있기 보다는 "레지스터"등에 담겨 있는 임시값"

	(n + 2) * 3 = 1; // error;

	++n = 1; // ++n => "4가 아닌 4가된 n 반환". 사용자가 할당한 메모리 n
			 // ++n = 1 는 ok. 즉, "++n" 은 lvalue

	n++ = 1; // error. n++ 은 연산에 과정에서 생성된 임시값 "3" 반환.. 
			 // "n++" 은 rvalue 
}	