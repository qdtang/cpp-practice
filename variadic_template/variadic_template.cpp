#include <iostream>

template <typename T>
void print(T&& t)
{
	std::cout << t << "\n";
}

template <typename T1, typename... Args>
void print(T1&& t, Args&& ... args)
{
	std::cout << t << "\n";
    if constexpr (std::is_same_v<T1&&, int&>) {
        t = 17;
    }
	print(args...);
}

template <typename... Args>
void print_wrapper(Args&& ... args)
{
	print(std::forward<Args>(args)...);
}

int main()
{
	int i = 9;
	print_wrapper(2, 9.4, i, "hello", .9f);
    std::cout << "after print, i = " << i << "\n";
	return 0;
}
