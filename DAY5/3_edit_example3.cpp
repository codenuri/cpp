#include <iostream>
#include <string>
#include <conio.h>

// 핵심 : validation 정책은 교체 가능해야 합니다.

// 방법 #1. 


class Edit
{
	std::string data;
public:

	// 핵심 : 공통성과 가변성의 분리
	// => 변하지 않은 코드 내부에 있는 변해야 하는 코드를 찾는다
	// => 변해야 하는 것을 가상함수로 분리 한다.

	virtual bool validate(char c)
	{
		return true;
	}

	std::string get_data()
	{
		data.clear();

		while (1)
		{
			char c = _getch();

			if (c == 13) break; 

			if (validate(c))		// "값의 유효성 여부" 는 가상함수를 호출해서 확인
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << '\n';
		return data;
	}
};

// 위 설계의 의도!!
// => 라이브러리 사용자가 validation 정책을 변경하려면
// => Edit 파생 클래스를 만들어서 약속된 가상함수(validate) 를 override 하라는 것

class NumEdit : public Edit 
{
public:
	bool validate(char c) override 
	{
		return isdigit(c);
	}
};

int main()
{
//	Edit e;		// 모든 문자 입력 가능
	NumEdit e;	// 숫자만 입력 가능
	while (1)
	{
		std::cout << e.get_data() << std::endl;
	}
}


