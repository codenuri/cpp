#include <iostream>

// template method 
// => 결국 가상함수를 사용하는 기법
// => 가상함수가 많아지만 가상함수 테이블 오버헤드 있습니다.
// => 임베디드에서는 CRTP 라는 기술도 널리 사용


template<typename T>
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
	void on_receive() { std::cout << "uart on_receive()\n";}
	void on_error()   { std::cout << "uart on_error()\n";}
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