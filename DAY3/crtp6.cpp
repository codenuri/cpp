#include <iostream>

// template 단점 
// => 코드 메모리 증가. 
// => 특히 임베디드 분야에서는 주의 

// 1. 클래스 템플릿을 만들때 "T" 를 사용하지 않은 멤버가 있다면
// 2. 템플릿이 아닌 기반 클래스를 만들어서 제공합니다.

// 이런 기술도 "이름" 이 있습니다.
// => "thin template" 또는 "template hoisting" 이라고 합니다

class UartBase 
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

	void on_receive() { std::cout << "UartBase on_receive()\n";}
	void on_error()   { std::cout << "UartBase on_error()\n";}
};

template<typename T>
class Uart  : public UartBase
{
public:
	void run_loop()		
	{
		int ret = recv();
		
		switch(ret)
		{
			case SUCCESS: 
				static_cast<T*>(this)->on_receive(); 
				break;

			case ERROR: 
				static_cast<T*>(this)->on_error(); 
				break;

			case UNKNOWN: break;
		}
	}

};

class MySerial : public Uart< MySerial > 
{
public:
	void on_receive() { std::cout << "MySerial on_receive()\n";}
	void on_error()   { std::cout << "MySerial on_error()\n";}
};

int main()
{
	MySerial uart;
	uart.open();
	uart.run_loop();
}