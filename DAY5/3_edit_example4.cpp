#include <iostream>
#include <string>
#include <conio.h>


// 변하는 것을 분리하는 2가지 기술
// #1. 변하는 것을 "가상함수로"   - template method, edit3.cpp
// #2. 변하는 것을 "다른클래스로" - strategy, 		  edit4.cpp

// Validation 정책을 별도의 클래스로 분리 합니다.
// => 그런데, 교체 가능해야 하므로 인터페이스를 먼저 설계 합니다.

struct IValidator 
{
	virtual bool validate(const std::string& s, char c) = 0;
	virtual bool is_complete(const std::string& s) { return true; }
	virtual ~IValidator() {}
};

// 주민 등록 번호 : 910    3      확인








class Edit
{
	std::string data;
	
	IValidator* val = nullptr; // 입력값의 유효성을 확인할 객체
public:
	void set_validator(IValidator* p) { val = p;}


	std::string get_data()
	{
		data.clear();

		while (1)
		{
			char c = _getch();

			if (c == 13 && (  val == nullptr || val->is_complete(data)) ) break;  

			if (val == nullptr || val->validate(data, c)) // 입력 값의 유효성 확인을 자신이 스스로 말고
			{											  // val 에 연결된 다른 객체에 위임 합니다.
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << '\n';
		return data;
	}
};

// 이제 Edit 에서 사용할 다양한 Validation 정책을 가진 클래스만 만들면 됩니다.
class LimitDigitValidator : public IValidator
{
	int value;
public:
	LimitDigitValidator(int n) : value{n} {}

	bool validate(const std::string& s, char c) override 
	{
		return s.size() < value && isdigit(c);
	}

	// 입력이 완료 되었는지(확인 버튼의 enable 여부 결정하는 함수)
	bool is_complete( const std::string& s) override 
	{
		return s.size() == value;
	}
};
int main()
{
	Edit e;
	LimitDigitValidator v(5);
	e.set_validator(&v);	// e 객체에 유효성을 확인하는 v 객체 전달

	while (1)
	{
		std::cout << e.get_data() << std::endl;
	}
}


