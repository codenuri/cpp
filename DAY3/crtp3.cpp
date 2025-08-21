#include <iostream>

// 1. C 언어로 해당 분야 프로그램을 작성합니다.
// 2. 관련된 함수와 데이타를 묶어서 클래스로 만듭니다.
// 3. 널리 알려진 다양한 디자인 기법을 적용합니다. - 대부분의 오픈소스가 이 과정으로 된것

// 핵심
// 클래스 내부에서 "변하지 않는 코드와 변하는 코드를 분리합니다."
// => 클래스 내부에 변하는 부분이 있으면 "가상함수로 분리" 합니다.

class Uart 
{
	int handle;
public:
	enum State
	{
		SUCCESS,
		ERROR,
		UNKNOWN
	};
	void open() {}	
	void write() {}
	int  recv() {return ERROR; 	}

	void run_loop()
	{
		// 보통은 이부분은 무한 루프 수행하면서, 수신하고, 성공/실패 처리
		// while(true) {}

		int ret = recv();
		
		switch(ret)
		{
			case SUCCESS: on_receive(); break;
			case ERROR: on_error(); break;
			case UNKNOWN: break;
		}
	}
	virtual void on_receive() { std::cout << "uart on_receive()\n";}
	virtual void on_error()   { std::cout << "uart on_error()\n";}
};
//-------------------------------------------------------
// 이제 RS232 작업이 필요하면 위 클래스에서 상속 받아서 
// 모든 기능을 물려 받고,
// 약속된 2개의 가상함수만 override 하면 됩니다.
// => template method 라는 이름을 가지는 기술 입니다
// => 아주 많이 사용되는 코딩 스타일 입니다.
// => 이런 스타일을 통채로 외워 두어야 합니다.
class MySerial : public Uart 
{
public:
	void on_receive() override { std::cout << "MySerial on_receive()\n";}
	void on_error()   override { std::cout << "MySerial on_error()\n";}
};

int main()
{
	MySerial uart;
	uart.open();
	uart.run_loop();
}