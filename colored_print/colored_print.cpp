// print out texts with custom colors & background colors & styles
#include <iostream>

#define ANSI_COLOR_RESET		"\033[0m"
#define ANSI_COLOR_RED			"\033[31m"
#define ANSI_COLOR_GREEN		"\033[32m"
#define ANSI_COLOR_YELLOW		"\033[33m"
#define ANSI_COLOR_BLUE			"\033[34m"
#define ANSI_COLOR_MAGENTA		"\033[35m"
#define ANSI_COLOR_CYAN			"\033[36m"
#define ANSI_BLACK_BACKGROUND	"\033[40m"
#define ANSI_BOLD				"\033[1m"

int main(int argc, char *argv[])
{
	std::cout << ANSI_COLOR_RED << "RED" << ANSI_COLOR_RESET << "\n";
	std::cout << ANSI_COLOR_GREEN << "GREEN" << "\n";
	std::cout << "sitll GREEN" << ANSI_COLOR_RESET << "\n";
	std::cout << ANSI_COLOR_CYAN << "CYAN" << ANSI_COLOR_RESET << "\n";
	// combined pattern
	std::cout << "\033[31;1;40m" << "RED & BOLD & BLACK_BACKGROUND" << ANSI_COLOR_RESET << "\n";
	std::cout << ANSI_COLOR_RED << ANSI_BOLD << "RED & BOLD" << ANSI_COLOR_RESET << "\n";

	return 0;
}