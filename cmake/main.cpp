#include "hello.h"

int main()
{
	auto hello = Hello();
	hello.speak();
	hello.speak("there");
	return 0;
}
