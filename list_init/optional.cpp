#include <iostream>
#include <experimental/optional>
#include <string>

std::experimental::optional<std::string> createStr(bool b)
{
	if (b) {
		// list initialization is supported since c++11
		return {"Godzilla"};
	}
	// list initialization
	return {};
}

int main(int argc, char *argv[])
{
	auto ret1 = createStr(false);
	auto ret2 = createStr(true);
	std::cout << "ret1 is " << ret1.value_or("empty") << "\n";
	std::cout << "ret2 is " << ret2.value_or("empty") << "\n";
	return 0;
}
