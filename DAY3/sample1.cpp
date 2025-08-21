#include <thread>
#include <chrono>
#include <cstdio>
#include <cstdbool>
#include <cstdint>
#include <cstdlib>
using namespace std::literals;
void delay(std::chrono::milliseconds ms) { std::this_thread::sleep_for(ms); }


// 주차장의 주차 가능 대수
#define MAX_SPOTS 8

// 주차장의 상태
// true면 점유, false면 비어있음
bool state[MAX_SPOTS];


bool read_sensor(int no)
{
	// 주차장의 no 위치의 주차칸 위에 설치된
	// 하드웨어에서 센서 데이타를 읽어 오는 코드
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
			return (int)i;
	}
	return -1;
}

void display_state()
{
	printf("free = %d, first = %d\n", free_count(), first_free());
}

int main(void)
{
	while (1)
	{
		update_state();
		display_state();
		delay(1000ms);
	}
}