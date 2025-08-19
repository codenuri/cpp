struct Rect
{
	int x, y, width, height;
};

void foo(int n) // call by value : 인자의 원본값을 절때 변경하지 않겠다는 약속
{				//                 아주 안전한 방식 
	n = 3;
}

//void goo(Rect rc) // call by value : 원본을 수정할수 없으므로 안전
				  //				 하지만, 복사본 생성에 대한 메모리 오버헤드 존재

void goo(const Rect& rc)  // call by const reference : 원본 수정이 안되어서 안전				   
{						  //				복사본도 없으므로 메모리 오버헤드도 없다
						  //                C++ 에서 가장 널리 사용하는 인자 전달방식
	
//	rc.x = 10; // error. 상수이므로 변경 불가
}

int main()
{
	int x = 100;

	// 어떤 함수에서 인자의 값을 절대 수정하면 안된다면
	foo(x);
	// foo 호출뒤에도 x 는 100을 유지 해야 한다.!
}
