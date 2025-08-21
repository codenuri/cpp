#include <iostream>

// template method 
// => 결국 가상함수를 사용하는 기법
// => 가상함수가 많아지만 가상함수 테이블 오버헤드 있습니다.
// => 임베디드에서는 CRTP 라는 기술도 널리 사용



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

	void run_loop()			// void run_loop(uart* this)
	{
		int ret = recv();
		
		switch(ret)
		{
			case SUCCESS: 
				on_receive(); // 이 코드는 this->on_receive() 입니다.
							  // 그런데 현재 this 는 uart* 입니다.
							  // 그리고, on_receive() 는 가상함수가 아니기 때문에
							  // static binding 하므로 포인터 타입에 따라 호출
							  // 그래서, 객체는 MySerial 이지만 포인터 타입이  uart라서
							  // uart 의 함수 호출
							  // 결론 : 파생 클래스가 다시 만들었지만 기반 클래스 함수 호출
							  // => 가상함수가 아니므로!
				break;

			case ERROR: on_error(); break;
			case UNKNOWN: break;
		}
	}

	void on_receive() { std::cout << "uart on_receive()\n";}
	void on_error()   { std::cout << "uart on_error()\n";}
};

class MySerial : public Uart 
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