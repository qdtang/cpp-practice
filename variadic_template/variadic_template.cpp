#include <iostream>
#include <sstream>

// print1: old fashion variadic template
template <typename T>
void print1(T&& t)
{
	std::cout << std::forward<T>(t) << "\n";
}

template <typename T, typename... Args>
void print1(T&& t, Args... args)
{
	std::cout << std::forward<T>(t) << " ";
	print1(std::forward<Args>(args)...);
}

// print2: using constexpr if
template <typename T, typename... Args>
void print2(T&& t, Args&&... args)
{
	std::cout << std::forward<T>(t);
	if constexpr (sizeof...(args)) {
		std::cout << " ";
		print2(std::forward<Args>(args)...);
	}
	else {
		std::cout << "\n";
	}
}

// print3: using fold expression
template <typename... Args>
void print3(Args... args)
{
	((std::cout << args << " "), ...);
	std::cout << "\n";
}


int main()
{
	int i = 9;
	print1(2, 9.4, i, "hello", .9f);
	print2(2, 9.4, i, "hello", .9f);
	print3(2, 9.4, i, "hello", .9f);
	return 0;
}
