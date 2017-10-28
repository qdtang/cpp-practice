#ifndef HELLO_H
#define HELLO_H

#include <string>

class Hello
{
public:
	Hello() = default;
	explicit Hello(const std::string& name) : _name(name) {}
	void greet() const;

private:
	std::string _name = {"there"};
};

#endif
