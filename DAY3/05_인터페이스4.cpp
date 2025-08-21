#include <iostream>

struct  IBlackBox 
{
	virtual void start_recording() = 0;
	virtual void stop_recording() = 0;
	virtual ~IBlackBox() {} 					
};

class Car 
{
	IBlackBox* blackbox = nullptr; 
public:
	void install_camera(IBlackBox* c) { blackbox = c;}

	void go()   { blackbox->start_recording();}
	void stop() { blackbox->stop_recording();}
};


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

