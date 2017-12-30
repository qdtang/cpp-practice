#include <iostream>
#include <iomanip>
#include <forward_list>

int main(int argc, char *argv[])
{
	std::forward_list<int> fl;
	std::cout << std::boolalpha;
	std::cout << (fl.before_begin() == fl.end()) << '\n';
	std::cout << (std::next(fl.before_begin()) == fl.begin()) << '\n';
	std::cout << (fl.begin() == fl.end()) << '\n';
	return 0;
}
