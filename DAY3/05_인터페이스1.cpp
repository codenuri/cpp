#include <iostream>

// 자동차의 BlackBox 를 생각해 봅시다.

// #1. 필요한 타입을 먼저 설계한다.
// => Camera 타입, Car 타입 

class Camera
{
public:
	void start_recording() { std::cout << "Start recording in HD quality\n"; }
	void stop_recording()  { std::cout << "Stop recording in HD quality\n"; }
};

// 미래에 더좋은 카메라가 나왔다.
class UHDCamera
{
public:
	void start_recording() { std::cout << "Start recording in UHD quality\n"; }
	void stop_recording()  { std::cout << "Stop recording in UHD quality\n"; }
};


class Car 
{
	Camera* cam;
public:
	void install_camera(Camera* c) { cam = c;}

	void go()   { cam->start_recording();}
	void stop() { cam->stop_recording();}
};


int main()
{
	Car car;
	Camera cam;

	car.install_camera(&cam);
	car.go();
	car.stop();

	// 이제 자동차에 새로운 블랙박스 카메라를 설치 하려고 한다 ??
	UHDCamera uhdcam;
	car.install_camera(&uhdcam); // ???될까요 ??
	car.go();
	car.stop();


}

