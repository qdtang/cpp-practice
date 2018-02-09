#include <iostream>

struct S
{
	void operator()(int, double); // NO implementation
	int operator()(double); // NO implementation
};

struct Movable {};
struct NonMovable
{
	NonMovable(NonMovable&& rhs) = delete;
};

struct NoDefaultConstructor
{
	NoDefaultConstructor() = delete;
};

template <typename T>
using move_assignment_t = decltype(std::declval<T&>() = std::declval<T&&>());

template <typename T, typename = void>
struct is_movable : std::false_type {};

template<typename T>
struct is_movable<T, std::void_t<move_assignment_t<T>>> : std::is_same<move_assignment_t<T>, T&> {};


int main(int argc, char *argv[])
{
	static_assert(std::is_invocable<S, int, double>::value, "");
	static_assert(std::is_invocable_r<int, S, double>::value, "");
	static_assert(std::is_same<std::result_of_t<S(int, double)>, void>::value, "");
	static_assert(std::is_same<std::invoke_result_t<S, int, double>, void>::value, "");
	std::invoke_result_t<S, double> i1;
	static_assert(std::is_same<decltype(i1), int>::value, "");
	std::cout << std::boolalpha << is_movable<Movable>::value << '\n';
	std::cout << is_movable<NonMovable>::value << '\n';
	std::cout << sizeof(std::cout) << '\n';
	std::cout << sizeof(std::cout << 42) << '\n'; // 42 should NOT be printed out.
	std::cout << sizeof(std::declval<NoDefaultConstructor>()) << '\n';
	return 0;
}
