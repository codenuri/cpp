#include <iostream>

/*
class Car 
{
//	UHDCamera cam;		// 특정 카메라 클래스이름 직접 사용. 교체 불가능한 경직된 디자인
//	IBlackBox* blackbox = nullptr; 	// 인터페이스 기반 사용. 교체 가능한 유연한 디자인
									// 단, 가상함수 기반이므로 가상함수 테이블 오버헤드가 있다.
}
*/

// 이번 예제의 핵심
// 가상함수의 오버헤드가 전혀 없이
// 카메라 교체가 가능하게 만들어 봅시다.


template<typename CAMERA>
class Car 
{
	CAMERA cam;	
public:
	void go()   { cam.start_recording();}
	void stop() { cam.stop_recording();}
};

class Camera 
{
public:
	inline void start_recording() { std::cout << "Start recording in HD quality\n"; }
	inline void stop_recording()  { std::cout << "Stop recording in HD quality\n"; }
};


class UHDCamera 
{
public:
	inline void start_recording() { std::cout << "Start recording in UHD quality\n"; }
	inline void stop_recording()  { std::cout << "Stop recording in UHD quality\n"; }
};

class AICamera 
{
public:
	inline void start_recording() { std::cout << "Start recording in AI quality\n"; }
	inline void stop_recording()  { std::cout << "Stop recording in AI quality\n"; }
};


int main()
{
	Car<UHDCamera> c1;
	c1.go();
	c1.stop();

	Car<AICamera> c2;
	c2.go();
	c2.stop();
}

