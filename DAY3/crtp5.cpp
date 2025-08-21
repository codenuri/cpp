#include <iostream>

// CRTP 기술
// => 기반 클래스를 만들때 파생 클래스의 이름을 사용할수 있게 하는 기술

// => 원리 : 기반 클래스가 템플릿 인데, 
//           파생 클래스가 상속받으면서 자신의 이름을 템플릿 인자로 전달하는 기술

// 예전에는 간단한 테크닉인데 요즘은 아주 중요해진 기술
// => 특히 임베디드 분야에서도 성능향상을 위해 널리 사용

// 다양한 활용가능하고

// 아래는 "가상이 아닌 함수를 가상함수 처럼 보이도록"




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