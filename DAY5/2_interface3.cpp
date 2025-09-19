#include <iostream>


// 강한 결합(tightly coupliing)
// => 클래스가 다른 클래스 사용시, 클래스 이름을 직접 사용하는것
// => ex) People::use_camera(HDCamera*)
// => 교체 불가능한 경직된 디자인

// 약한 결합(loosely coupliing)
// => 클래스가 다른 클래스 사용시, 클래스 이름이 아닌 규칙을 담은 
//    인터페이스를 통해서 사용하는 것
// => ex) People::use_camera(ICamera*)
// => 교체 가능한 유연한 디자인

//------------------
// 추상 클래스 와 인터페이스라는 용어가 혼용되어 사용되는데,,
// 보통 아래 기준으로 분류 합니다.
// 추상 클래스 : 지켜야 하는 규칙 + 다른 멤버도 있는 경우
// 인터 페이스 : 지켜야 하는 규칙만 있는 경우

// C#, Java 는 별도의 interface, abstract 키워드가 있어서 명확하데,,
// C++은 별도 키워드 없고, 추상 클래스 문법만 존재, 
// 따라서 위 처럼 분류.

//--------------------------------------------------
// 규칙 : "모든 카메라는 아래 클래스로 부터 파생 되어야 한다" 라고 표현하지 말고
//        "모든 카메라는 아래 인터페이스를 구현해야 한다" 라고 표현하는 것이 좋습니다.

// 인터페이스 만들때 class 로 해도 되지만, 많은 오픈소스가 struct 를 선호 합니다
// => 이유는 단순합니다.
// => public 한줄을 제거 할수 있기 때문에

//#define interface struct  // <== 예전에는 이런 기술도 사용. 요즘은 잘 사용안함.

//class ICamera 
struct ICamera 
//interface ICamera 
{
	virtual void take() = 0;
	virtual ~ICamera() {}   // 인터페이스도 결국 문법적으로는 기반 클래스
							// 따라서 "가상 소멸자" 가 되어야 합니다. 
};






class People
{
public:
	void use_camera(ICamera* c) { c->take(); }
};


class Camera : public ICamera
{
public:
	void take() { std::cout << "take picture\n";}
};

class HDCamera : public ICamera
{
public:
	void take() { std::cout << "take HD picture\n";}
};

class UHDCamera : public ICamera
{
public:
	void take() { std::cout << "take UHD picture\n";}
};

int main()
{
	People p;

	Camera c;
	p.use_camera(&c);

	HDCamera hc;
	p.use_camera(&hc); 

	UHDCamera uhc;
	p.use_camera(&uhc); 
}

