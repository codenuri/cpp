
// 후위 반환타입 장점 #1
// => 복잡한 반환 타입을 쉽게 표기할수 있다.

void foo(int a) {}

// ? 채워 보세요
// => 함수의 주소를 반환하는 함수

void(* goo() )(int)
{
	return &foo; 
}

// 후위 반환으로 하면 쉽습니다.
auto hoo() -> void(*)(int)
{
	return &foo;
}

int main()
{

}