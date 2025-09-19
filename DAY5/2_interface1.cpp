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

