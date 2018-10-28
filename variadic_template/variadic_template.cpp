#include <iostream>

// print1: old fashion variadic template version
template <typename T>
void print1(T&& t)
{
	std::cout << std::forward<T>(t) << "\n";
}

template <typename T, typename... Args>
void print1(T&& t, Args... args)
{
	std::cout << std::forward<T>(t) << "\n";
	print1(std::forward<Args>(args)...);
}

// print2: version using constexpr if
template <typename T, typename... Args>
void print2(T&& t, Args&&... args)
{
	std::cout << std::forward<T>(t) << "\n";
	if constexpr (sizeof...(args)) {
		print2(std::forward<Args>(args)...);
	}
}

// print3: version using fold expression
template <typename... Args>
void print3(Args... args)
{
	(std::cout << ... << args) << "\n";
}


int main()
{
	int i = 9;
	print1(2, 9.4, i, "hello", .9f);
	print2(2, 9.4, i, "hello", .9f);
	print3(2, 9.4, i, "hello", .9f);
	return 0;
}
