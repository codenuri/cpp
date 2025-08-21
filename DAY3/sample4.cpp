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
	ISensor* sensor = nullptr; 

	bool state[MAX_SPOTS];

public:
	void set_sensor(ISensor* s) { sensor = s;}

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