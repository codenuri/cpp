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



int main(void)
{
	ParkingLot lot;

	WifiSensor wifisensor;
	lot.set_sensor(&wifisensor);

	while (1)
	{
		lot.update_state();
		lot.display_state();
		delay(1000ms);
	}
}