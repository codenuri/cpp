// sample1.cpp
#include <thread>
#include <chrono>
#include <cstdio>
#include <cstdint>
#include <cstdlib>
using namespace std::literals;
void delay(std::chrono::milliseconds ms) { std::this_thread::sleep_for(ms); }

// sample1.cpp 문제점
// 1. 주차 상태 배열(state)가 전역변수 입니다.
// => 어디서라도 변경 가능합니다.

// 해결책 
// => 객체지향으로 클래스로 설계하고 private 에 보호하면 안전합니다.


//#define MAX_SPOTS 8		// 매크로는 전처리기가 처리. 좋지 않습니다.

constexpr unsigned int MAX_SPOTS = 8; // constexpr 컴파일러가 처리. 위코드 보다 좋은 방식

class ParkingLot 
{
private:
	bool state[MAX_SPOTS];

public:
	bool read_sensor(int no)
	{
		bool state = (bool)(rand() % 2);
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
	while (1)
	{
		lot.update_state();
		lot.display_state();
		delay(1000ms);
	}
}