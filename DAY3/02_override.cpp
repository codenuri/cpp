// 7_가상함수2.cpp  147 page ~

class Shape
{
public:
	virtual void draw() {};
	virtual void clone() const {};
	virtual void move() {};
};

class Rect : public Shape
{
public:
	// 가상함수 문법 정리
	// #1. 가상함수를 override 할때는 virtual 이 있어도 되고 없어도 됩니다.
	// => 그런데, 가독성을위해서 virtual 붙이는 것을 권장 - MISRA C++ 2008
//	void draw()  {}
//	virtual void draw()  {} // 위와 동일

	// #2. 가상함수 override 시 오타가 있어도 에러 아닙니다.
	// => 컴파일러가 다른 함수로 취급.
	// => 이런 현상 때문에 버그가 아주 많이 발생	
	//virtual void Draw() {};

	// #3. 위 문제를 해결하기 위해 C++11 부터 "override" 키워드 등장

//	virtual void Draw() override {} // 새로운 함수가 아니고, 기반 클래스 함수 재정의한다고 알림
									// 그런데, 기반 클래스에 Draw 없으므로 에러
									
	virtual void draw() override {} // ok

	// 결론
	// 가상함수를 처음 만들때는 virtual 사용
	// 가상함수를 override 할때는 "override" 를 붙이세요 - 없어도 되지만, 강력 권장!
};
int main()
{

}
