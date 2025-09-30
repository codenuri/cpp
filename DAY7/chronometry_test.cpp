#include <thread>
#include <string>
#include <iostream>
#include <chrono>
#include <vector>
#include "chronometry.h"
using namespace std::literals;

int& foo(double d, int& n, const std::string& s)
{
	std::this_thread::sleep_for(3s);
	return n;
}

int main()
{
	int x = 0;
	int& ret = chronometry(foo, 3.4, x, "hello"); // foo(3.4, x, "hello");
}