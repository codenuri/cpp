#include <iostream>
#include <string>
#include <conio.h>

class Edit
{
	std::string data;
public:
	std::string get_data()
	{
		std::cin >> data;
		return data;
	}
};
int main()
{
	Edit e; // 이순간 화면에 Edit 컨트롤이 나타난다고 가정
			// 사용자가 Edit 에 입력한 값을 꺼내는 멤버 함수가 get_data()
	while (1)
	{
		std::cout << e.get_data() << std::endl;
	}
}


