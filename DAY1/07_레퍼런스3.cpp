struct Rect
{
	int x, y, width, height;
};

void foo(int n) // call by value : 인자의 원본값을 절때 변경하지 않겠다는 약속
{				//                 아주 안전한 방식 
	n = 3;
}

void goo(Rect rc) // call by value : 
{

}

int main()
{
	int x = 100;

	// 어떤 함수에서 인자의 값을 절대 수정하면 안된다면
	foo(x);
	// foo 호출뒤에도 x 는 100을 유지 해야 한다.!
}
