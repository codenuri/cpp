#include <iostream>

// Car 와 Camera 등을 먼저 만들지 말고

// 규칙을 먼저 설계합니다.

// 규칙 : 모든 BlackBox 용 카메라는 아래 클래스로 부터 상속 받아야 합니다.

class IBlackBox 
{
public:
	virtual void start_recording() = 0;
	virtual void stop_recording() = 0;
};

// 규칙만 있고, 아직 실제 카메라는 없지만
// 사용하는 코드를 먼저 만들수도 있습니다.
// => 규칙 대로만 사용하면 되므로
// => Car 는 "규칙(추상)"에만 의존하고, 구체(실제 제품)은 알지 못합니다.
class Car 
{
	// 핵심 : Car 는 규칙에만 의존해야 합니다. (약속 기반의 설계)
	IBlackBox* blackbox = nullptr; 
public:
	void install_camera(IBlackBox* c) { blackbox = c;}

	void go()   { blackbox->start_recording();}
	void stop() { blackbox->stop_recording();}
};

// 이제 카메라 제조사는 규칙대로 설계해야 합니다.
class Camera : public IBlackBox
{
public:
	void start_recording() { std::cout << "Start recording in HD quality\n"; }
	void stop_recording()  { std::cout << "Stop recording in HD quality\n"; }
};


class UHDCamera : public IBlackBox
{
public:
	void start_recording() { std::cout << "Start recording in UHD quality\n"; }
	void stop_recording()  { std::cout << "Stop recording in UHD quality\n"; }
};

class AICamera : public IBlackBox
{
public:
	void start_recording() { std::cout << "Start recording in AI quality\n"; }
	void stop_recording()  { std::cout << "Stop recording in AI quality\n"; }
};


int main()
{
	Car car;
	Camera cam;

	car.install_camera(&cam);
	car.go();
	car.stop();

	UHDCamera uhdcam;
	car.install_camera(&uhdcam);  // ok
	car.go();
	car.stop();

	AICamera aicam;
	car.install_camera(&aicam);  // ok
	car.go();
	car.stop();	
}

