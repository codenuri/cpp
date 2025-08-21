#include <iostream>

// UART(RS232) 자체를 하나의 타입으로 설계 합니다.
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
	void open()
	{
		// RS232 를 open 해서 handle 에 보관
		// handle = C 언어 함수로 RS232 Open
	}	
	void write() {}

	int  recv() {return ERROR; 	}

	void run_loop()
	{
		// RS232 에서 data 를 수신하고, 에러 처리
		int ret = recv();
		
		switch(ret)
		{
			case SUCCESS: break;
			case ERROR: break;
			case UNKNOWN: break;
		}
	}
};

int main()
{
	Uart uart;
	uart.open();
	uart.run_loop();
}