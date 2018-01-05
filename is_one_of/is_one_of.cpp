#include <iostream>

// primary template without implementation.
// All cases are taken care of by partial specializations.
template<typename T, typename... P0toN>
struct is_one_of;

// partial specialization #1: empty type list
template<typename T>
struct is_one_of<T> : std::false_type {};

// partial specialization #2: T is the head of type list
template<typename T, typename... P1toN>
struct is_one_of<T, T, P1toN...> : std::true_type {};

// partial specialization #3: T is not the head of type list, trigger the recursion
template<typename T, typename P0, typename... P1toN>
struct is_one_of<T, P0, P1toN...> : is_one_of<T, P1toN...> {};

template<typename T, typename... P0toN>
constexpr bool is_one_of_v = is_one_of<T, P0toN...>::value;


int main(int argc, char *argv[])
{
	std::cout << std::boolalpha << is_one_of_v<void> << "\n";
	std::cout << std::boolalpha << is_one_of_v<void, void, double, int> << "\n";
	std::cout << std::boolalpha << is_one_of_v<void, int, void, double> << "\n";
	std::cout << std::boolalpha << is_one_of_v<void, int, double, void> << "\n";
	std::cout << std::boolalpha << is_one_of_v<void, int, double, void*> << "\n";
	std::cout << std::boolalpha << is_one_of_v<void, int, double, float> << "\n";
	return 0;
}
