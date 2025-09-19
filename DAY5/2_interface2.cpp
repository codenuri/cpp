#include <iostream>


// 카메라와 카메라 사용 코드를 마음대로 만들지 말고...
// 규칙을 먼저 설계 합니다.

// 규칙 : 모든 카메라는 아래 클래스로 부터 파생 되어야 한다

class ICamera 
{
public:
	virtual void take() = 0;
};

// 아직 진짜 카메라는 없지만 "규칙"이 있습니다.
// 카메라 사용자는 규칙 대로만 사용하면 됩니다.

class People
{
public:
	void use_camera(ICamera* c) { c->take(); }
};

// 이제 모든 카메라는 규칙을 지켜야 합니다.
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
	p.use_camera(&uhc); // ok.. 나중에 추가된 카메라도 
						// People 클래스 수정없이 사용할수 있다.
						// OCP 를 만족하는 좋은 코드!!
}

