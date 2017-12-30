#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
	std::vector<bool> v = {true, false};
	std::cout << typeid(v[0]).name() << "\n";
	return 0;
}
