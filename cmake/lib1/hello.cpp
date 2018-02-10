#include "hello.h"
#include <iostream>

void Hello::speak(const char* prompt) const
{
	std::cout << "Hello, " << (prompt ? prompt : "") << '\n';
}
