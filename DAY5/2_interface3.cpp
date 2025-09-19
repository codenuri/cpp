#include <iostream>


// 강한 결합(tightly coupliing)
// => 클래스가 다른 클래스 사용시, 클래스 이름을 직접 사용하는것
// => ex) People::use_camera(HDCamera*)
// => 교체 불가능한 경직된 디자인












// 규칙 : 모든 카메라는 아래 클래스로 부터 파생 되어야 한다

class ICamera 
{
public:
	virtual void take() = 0;
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

