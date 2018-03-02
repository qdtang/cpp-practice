#include "hello.h"
#include <iostream>

void Hello::speak(const char* prompt) const
{
	std::cout << "Hello";
	if (prompt) {
		std::cout << ", " << prompt;
	}
	std::cout << "!\n";
}
