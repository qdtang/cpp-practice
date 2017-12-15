#include <iostream>
#include <optional>
#include <string>
#include <any>
#include <tuple>

std::optional<std::string> createStr(bool b)
{
	if (b) {
		return { "Hello" };
	}
	return {};
}

int main()
{
	std::cout << createStr(true).value_or("empty") << "\n";
	std::cout << createStr(false).value_or("empty") << "\n";

	using namespace std::string_literals;
	std::any an = 12;
	std::cout << std::any_cast<int>(an) << "\n";
	an = "Literal"s;
	std::cout << std::any_cast<std::string>(an) << "\n";

	auto tp = std::make_tuple(1, 1.2, "1.3");
	std::cout << std::get<1>(tp) << "\n";

	return 0;
}
