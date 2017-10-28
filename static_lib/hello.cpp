#include "hello.h"
#include <iostream>

void Hello::greet() const
{
	std::cout << "Hello, " << _name << "\n";
}
