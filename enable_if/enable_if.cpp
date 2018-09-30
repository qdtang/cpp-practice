#include <iostream>
#include <string>
#include <type_traits>

template<typename T, typename Enable = void>
struct Test
{
	constexpr static int value = 0;
};

template <typename T>
struct Test <T, typename std::enable_if<std::is_class<T>::value>::type>
{
	constexpr static int value = 1;
};

template <typename T>
struct Test <T, typename std::enable_if<std::is_floating_point<T>::value>::type>
{
	constexpr static int value = 2;
};

template <typename T>
typename std::enable_if<std::is_same<T, int>::value>::type
func(T)
{
	std::cout << "T is an int\n";
}

template <typename T>
typename std::enable_if<!std::is_same<T, int>::value>::type
func(T)
{
	std::cout << "T is not an int\n";
}

int main(int argc, char *argv[])
{
	std::cout << Test<int>::value << "\n";
	std::cout << Test<std::string>::value << "\n";
	std::cout << Test<double>::value << "\n";
	func(0);
	func(0.1);
	return 0;
}
