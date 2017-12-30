#include <iostream>
#include <chrono>
#include <ratio>

int main(int argc, char *argv[])
{
	typedef std::ratio<5, 15> OneThird;
	typedef std::ratio<2, 4> Half;
	typedef std::ratio_add<OneThird, Half> Sum;
	std::cout << "OneThird: " << OneThird::num << '/' << OneThird::den << '\n';
	std::cout << "Half: " << Half::num << '/' << Half::den << '\n';
	std::cout << "Sum: " << Sum::num << '/' << Sum::den << '\n';
	auto d = std::chrono::duration<int, OneThird>{12};
	auto d_in_sec = std::chrono::duration_cast<std::chrono::seconds>(d);
	std::cout << d.count() << " of " << OneThird::num << '/' << OneThird::den
			<< " second is " << d_in_sec.count() << " seconds\n";

	auto now = std::chrono::system_clock::now();
	auto one_day_ago = now - std::chrono::hours{24};
	auto t = std::chrono::system_clock::to_time_t(one_day_ago);
	std::cout << "one day ago is " << asctime(localtime(&t));

	return 0;
}
