#include <iostream>

// 강한결합(tightly coupling)
// => 하나의 클래스가 다른 클래스 사용시 이름 를 직접 사용
// => ex) Car::install_camera(UHDCamera*)
// => 확장성 없는 경직된 디자인.

// 약한결합(loosely coupling)
// => 하나의 클래스가 다른 클래스 사용시 규칙을 담은 인터페이스를 통해서 사용하는것
// => ex) Car::install_camera(IBlackBox*)
// => 확장성 있는 유연한 디자인.

//-----------------------------------------
// 인터페이스 : 지켜야 하는 규칙만 가진것
// 추상클래스 : 지켜야 하는 규칙 + 다른 멤버도 있는 경우

// C#, Java : 별도의 abstract, interface 라는 키워드 있음. 명확히 분류
// C++ 은 별도 키워드 없음. 단지 위 내용으로 구분
//-------------------------------------------------------------------

// 규칙 : "모든 BlackBox 용 카메라는 아래 클래스로 부터 상속 받아야 합니다." 라고 표현하지말고
//        "모든 BlackBox 용 카메라는 아래 인터페이스를 구현 해야 한다." 라고 표현합니다.

// 인터페이스 설계시 class 로 해도 전혀 문제 없는데..
// 많은 개발자가 struct 선호
// => 이유는 public 표기하지 않아도 디폴트가 public 이므로

//class IBlackBox 
struct  IBlackBox 
{
	virtual void start_recording() = 0;
	virtual void stop_recording() = 0;

	virtual ~IBlackBox() {} // 인터페이스도 결국 문법적으로는 기반 클래스
							// 소멸자를 반드시 가상 소멸자로 !
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

