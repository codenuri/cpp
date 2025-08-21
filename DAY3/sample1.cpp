#include <thread>
#include <chrono>
#include <cstdio>
#include <cstdbool>
#include <cstdint>
#include <cstdlib>
using namespace std::literals;
void delay(std::chrono::milliseconds ms) { std::this_thread::sleep_for(ms); }


// �������� ���� ���� ���
#define MAX_SPOTS 8

// �������� ����
// true�� ����, false�� �������
bool state[MAX_SPOTS];


bool read_sensor(int no)
{
	// �������� no ��ġ�� ����ĭ ���� ��ġ��
	// �ϵ����� ���� ����Ÿ�� �о� ���� �ڵ�
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