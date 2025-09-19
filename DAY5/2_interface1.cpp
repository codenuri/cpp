#include <iostream>

class Camera
{
public:
	void take() { std::cout << "take picture\n";}
};

class HDCamera
{
public:
	void take() { std::cout << "take HD picture\n";}
};

class People
{
public:
	void use_camera(Camera* c) { c->take(); }
	void use_camera(HDCamera* c) { c->take(); }
};

int main()
{
	People p;

	Camera c;
	p.use_camera(&c);

	HDCamera hc;
	p.use_camera(&hc); // ok
}

// 위 코드는 OCP 위반 입니다.
// => 미래에 새로운 HDCamera 가 추가 되었는데,
// => 이 추가 때문에 People 코드가 수정되었습니다.
// 나쁜 디자인 입니다.
