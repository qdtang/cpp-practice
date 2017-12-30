#include <iostream>
#include <tuple>

int main(int argc, char *argv[])
{
	auto t = std::make_tuple(1, 4.8, "hello");
	double d;
	std::tie(std::ignore, d, std::ignore) = t;
	std::cout << d << "\n";
	// structed binding declaration (since c++17)
	auto& [i, f, s] = t;
	std::cout << i << " " << f << " " << s << "\n";
	return 0;
}
