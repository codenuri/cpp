// sample1.cpp
#include <thread>
#include <chrono>
#include <cstdio>
#include <cstdint>
#include <cstdlib>
using namespace std::literals;
void delay(std::chrono::milliseconds ms) { std::this_thread::sleep_for(ms); }

constexpr unsigned int MAX_SPOTS = 8; 

struct ISensor 
{
	virtual bool read_sensor(int no) = 0;
	virtual ~ISensor() {}
};

class RFSensor : public ISensor
{
public:
	bool read_sensor(int no) override 
	{
		return (bool) (rand() % 2);
	}
};

class WifiSensor : public ISensor
{
public:
	bool read_sensor(int no) override 
	{
		return (bool) (rand() % 2);
	}
};
//--------------------------------------
// 주차장 상황이 변경될때 마다 Display 해야 하는데
// 주차장 정문, 인터넷, 고객 sms 등 다양한 방식이 가능해야 합니다.

struct IDisplay 
{
	virtual void display(int free_count, int first_free) = 0;
	virtual void display_all( bool* state) {} // 배열을 통채로 전달하는 함수
											 // 전체상황 출력 가능하게
											 // =0 이 아니므로 필요 한 경우만 구현
	virtual ~IDisplay() {}
};




class ParkingLot 
{
private:
	ISensor* sensor = nullptr; 
	IDisplay* display[256]; // 최대 256개의 display 객체 연결가능
	int display_cnt = 0;

	bool state[MAX_SPOTS];
public:
	void set_sensor(ISensor* s) { sensor = s;}
	void add_display(IDisplay* d) { display[display_cnt++] = d;}


	bool read_sensor(int no)
	{

		bool state = sensor->read_sensor(no);
		return state;
	}

	void update_state()
	{
		for (int i = 0; i < MAX_SPOTS; i++)
		{
			state[i] = read_sensor(i);
		}
		// 주차장 상태가 변경되었으므로
		// 이제 등록된 모든 display 객체에 전달합니다
		for( int i = 0; i < display_cnt; i++)
		{
			display[i]->display(free_count(), first_free());
			display[i]->display_all(state); // 전체 상태를 담은 배열도 전달
		}
	}


	int free_count(void)
	{
		int c = 0;

		for (int i = 0; i < MAX_SPOTS; i++)
		{
			if (!state[i])
				c++;
		}
		return c;
	}


	int first_free(void)
	{
		for (int i = 0; i < MAX_SPOTS; i++)
		{
			if (!state[i])
				return i;
		}
		return -1;
	}

	void display_state()
	{
		printf("free = %d, first = %d\n", free_count(), first_free());
	}
};

// 주차장 상황이 변경될때 마다 Display 를 책임지는 클래스
class WebPageDisplay : public IDisplay 
{
public:
	void display(int free_count, int first_free) override 
	{
		// 여기서 홈페이지를 수정하는 코드 작성
		printf("[WEB] 빈자리 : %d, 첫번째 빈자리 위치 : %d\n",free_count, first_free );
	}
	void display_all(bool* state) override 
	{
		printf("[WEB] 전체 주차상황을 출력\n");
	}
};

class CustomerSMSSender : public IDisplay 
{
public:
	void display(int free_count, int first_free) override 
	{
		printf("[SMS 문자] 빈자리 : %d, 첫번째 빈자리 위치 : %d\n",free_count, first_free );
	}
};



int main(void)
{
	ParkingLot lot;

	WifiSensor wifisensor;
	lot.set_sensor(&wifisensor);

	// 주차 상황이 변경될때 마다 약속된 곳에 출력하는 객체 연결
	WebPageDisplay d1;
	CustomerSMSSender d2;

	lot.add_display(&d1);
	lot.add_display(&d2);

	while (1)
	{
		lot.update_state();
		lot.display_state();
		delay(1000ms);
	}
}

// 결론 
// 1. 주차장 센서등을 교체 했으면
// => ISensor 인터페이스를 구현한 클래스를 만들어서 
// => 새로운 센서로 부터 데이타를 읽는 코드만 작성하면 됩니다.
// => ParkingLot 은 변경될 필요 없습니다

// 2. 주차장 상태 정보를 "다양한 형태로 보여 주고 싶다."
// => IDisplay 인터페이스로 부터 파생된 클래스를 만들어서
// => 출력 방법을 제공하세요
// => 그리고 ParkingLog 에 add_display() 로 부착하세요
// => 복습시 remove_display()도 만들어 보세요

// 결국
// 1. sample1.c 방식의 C 코드를 먼저 완벽히 이해 하세요
// 2. sample2.c 처럼 class 로 만들면 state 배열을 private 으로 보호할수 있어서 아주 좋습니다.
// 3. ISensor 인터페이스 도입으로
// => Sensor 하드웨어 교체시, 해당 하는 코드만 작성할수있게 되었습니다.

// 4. IDisplay 도입으로 "주차장 상태를 여러방식으로 알릴수 있게 되었습니다."

// 복습 할때 "위 단계를 차례대로 복습하면서 의미를 생각해 보세요"
