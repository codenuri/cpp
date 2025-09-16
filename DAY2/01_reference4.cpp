struct BigData
{
	int buff[1024];
};

void foo(int n) // call by value : 원본을 수정하지 않을 것이라는 약속
{				// 함수 안에서 어떠한 작업을 해도, 복사본이 변경될뿐, 원본은 수정되지 않는다
	n = 10;
}

//void goo( BigData bd) //  call by value: 원본을 수정할수 없어서 안전하지만, 복사본의 오버헤드가 있다.
void goo( const BigData& bd) // const & : 복사본의 오버헤드 없이, 원본을 수정하지 못하게
{							//            안전하게 사용하기 위한 기술
	// const 이므로 bd를 변경하는 코드가 있으며 컴파일 에러
}
int main()
{
	int x = 100;

	// 어떤 함수에서 인자의 값을 절대 수정하면 안된다면
	foo(x);

	BigData b;
	goo(b);
}
