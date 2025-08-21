// sample1.cpp
#include <thread>
#include <chrono>
#include <cstdio>
#include <cstdint>
#include <cstdlib>
using namespace std::literals;
void delay(std::chrono::milliseconds ms) { std::this_thread::sleep_for(ms); }

// 아래 코드는 C 언어 스타일 입니다.

// 주차장의 주차 댓수
#define MAX_SPOTS 8

// 각 칸의 주차여부 - 배열로 관리
// true : 사용중, false : 빈자리
bool state[MAX_SPOTS];


// 주차자리 한칸의 정보 읽기
bool read_sensor(int no)
{
	// 각 주차 자리 위의 센서를 읽어 오는 부분 이라고 가정
	// H/W 관련 코드가 이곳에 있게 됩니다.
	bool state = (bool)(rand() % 2);
	return state;
}

// 주차장 전체 - 즉, 8 자리의 상태를 확인해서
// 배열 update
void update_state()
{
	for (int i = 0; i < MAX_SPOTS; i++)
	{
		state[i] = read_sensor(i);
	}
}

// 비어 있는 자리 갯수 반환
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

// 입구 부터 가장 가까운 빈자리는 어디 인가 ?
int first_free(void)
{
	for (int i = 0; i < MAX_SPOTS; i++)
	{
		if (!state[i])
			return i;
	}
	return -1;
}

// 현재 주차장 상황을 화면에 보여주는 함수
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