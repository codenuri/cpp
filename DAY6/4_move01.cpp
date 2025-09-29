#include <iostream>
#include <string>
#include <vector>

// move 개념

int main()
{
	std::string s1 = "hello";
	std::string s2 = "hello";

	std::string s3 = s1;	// 자원(문자열)의 깊은복사
	std::string s4 = std::move(s2);	// s2가 s4의 자원을 빼앗아감..
									// 자원의 이동(move)

	std::cout << s1 << std::endl; // "hello"
	std::cout << s2 << std::endl; // "" 


}

