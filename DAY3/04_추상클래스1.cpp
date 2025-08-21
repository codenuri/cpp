// 추상 클래스 : 순수 가상함수가 한개 이상 있는 클래스
// 특징 : 객체를 만들수 없다.
// 의도 : 약속된 함수를 만드시 만들라고 시키는 것
//       규칙을 만들때 사용하는 문법 
class Shape
{
public:
	virtual void Draw()  = 0; // 순수 가상함수(pure virtual function )
							  // 함수 구현이 없고, "= 0" 으로 끝나는 함수
};
class Rect : public Shape
{
public:
	// Draw()의 구현부를 제공하지 않으면 Rect 도 추상이다.
	// Draw()의 구현부를 제공하면 추상이 아니다.
	void Draw() override {} 
};
int main()
{
	Shape s; // error
	Shape* s; // ok. 포인터는 만들수 있다.
	Rect  r; // ok 
}


