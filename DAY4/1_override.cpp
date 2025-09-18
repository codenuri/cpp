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
	// #1. 가상함수 재정의 시 virtual 은 표기해도 되고, 생략해도 됩니다.
	// => 가독성을 위해서는 virtual 을 표기하는게 좋습니다.(C++98 시절)
	// void draw()  {};		
	virtual void draw()  {};

	// #2. 가상함수 재정의시 실수(오타)가 있다면
	// => 에러가 아닙니다.
	// => 컴파일러는 다른 가상함수를 추가했다고 생각합니다
//	virtual void clone() {}
//	virtual void move(int n) {}

	// #3. #2 같은 문제점을 해결하기 위해 C++11 부터 override 키워드 도입
	// => 컴파일러에게 기반 클래스 함수를 다시 만든다고 알려주는것
	// => 실수(오타)등이 있다면 컴파일 에러. 
	virtual void clone() 	 override {} // error
	virtual void move(int n) override {} // error
};

int main()
{

}












