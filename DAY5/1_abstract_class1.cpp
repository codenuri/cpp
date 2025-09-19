
// 추상 클래스(abstract class) 
// 정의 : 순수 가상함수가 한개 이상 있는 클래스
// 특징 : 객체를 만들수 없다. 단, 포인터 변수는 만들수 있다.
// 의도 : 약속된 멤버 함수를 반드시 만들라고 지시하기 위한 문법
class Shape
{
public:
	virtual void draw()  = 0; // 순수 가상함수 (pure virtual function )
							  // 특징 : 구현이 없고, = 0 으로 표기
};
class Rect : public Shape
{
public:
	// draw() 의 구현부를 제공하지 않으면 Rect 도 추상
	// draw() 의 구현부를 제공하면       Rect 는 추상 아님
	void draw() override {}  // 구현을 제공했으므로 Rect 는 추상 아님. 
};
int main()
{
	Shape s;  // error. 
	Shape* p; // ok. 
	Rect  r;  // ?	
}


