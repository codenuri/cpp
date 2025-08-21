// sample1.cpp
#include <thread>
#include <chrono>
#include <cstdio>
#include <cstdint>
#include <cstdlib>
using namespace std::literals;
void delay(std::chrono::milliseconds ms) { std::this_thread::sleep_for(ms); }

// 이번 예제의 핵심

// ParkingLot 클래스에서 "잦은 변경이 일어나는 부분이 있는지 확인하세요"
// => 미래에 변경가능성이 있으면
// => ParkingLot 분리하세요
// => "인터페이스 기반" 또는 "policy base design"




constexpr unsigned int MAX_SPOTS = 8; 

// 주차장 센서는 "더 좋은 제품으로 교체" 될수있습니다.
// => 센서에서 데이타를 읽는 부분을 교체 가능한 설계가 필요 합니다.

// 모든 센서에서 데이타를 읽는 클래스가 지켜야 하는 규칙
struct ISensor 
{
	virtual bool read_sensor(int no) = 0;
	virtual ~ISensor() {}
};

// 이제 다양한 H/W Sensor 에서 부터 읽어오는 클래스를 만들면 됩니다.
// Sensor H/W 교체시 아래 클래스만 새로 만들면 됩니다.
class RFSensor : public ISensor
{
public:
	bool read_sensor(int no) override 
	{
		return (bool) rand() % 2;
	}
};

class WifiSensor : public ISensor
{
public:
	bool read_sensor(int no) override 
	{
		return (bool) rand() % 2;
	}
};




class ParkingLot 
{
private:
	ISensor* sensor = nullptr; // 센서에서 읽을때 사용

	bool state[MAX_SPOTS];

public:
	void set_sensor(ISensor* s) { sensor = s;}

	bool read_sensor(int no)
	{
		// 실제로 센서에서 읽을때 어떻게 읽을지는 
		// ParkingLog 클래스에는 없습니다.
		// set_sensor() 로 전달된 정책클래스에 의존 합니다.
		bool state = sensor->read_sensor(no);
		return state;
	}

	void update_state()
	{
		for (int i = 0; i < MAX_SPOTS; i++)
		{
			state[i] = read_sensor(i);
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

//	RFSensor rfsensor;
//	lot.set_sensor(&rfsensor);

	// 센서가 바뀌면 아래 처럼만 변경하면 됩니다.
	WifiSensor wifisensor;
	lot.set_sensor(&wifisensor);

	while (1)
	{
		lot.update_state();
		lot.display_state();
		delay(1000ms);
	}
}