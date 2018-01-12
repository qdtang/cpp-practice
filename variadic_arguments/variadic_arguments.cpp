#include <iostream>
#include <cstdarg>

#define TEXT_COLOR_RED 		"\033[31m"
#define TEXT_COLOR_CYAN 	"\033[36m"
#define TEXT_COLOR_RESET 	"\033[0m"

#define fatal(...) \
	fprintf(stderr, TEXT_COLOR_CYAN); \
	fprintf(stderr, "fatal occurs at %s:%u\n", __FILE__, __LINE__); \
	fprintf(stderr, __VA_ARGS__); \
	fprintf(stderr, TEXT_COLOR_RESET); \
	exit(-1);

constexpr int MAX_ERR_LENGTH = 2048;

void printError(const char* fmt, ...)
{
	char buf[MAX_ERR_LENGTH];
	va_list args;
	va_start(args, fmt);
	vsprintf(buf, fmt, args);
	va_end(args);
	fprintf(stderr, TEXT_COLOR_RED "%s" TEXT_COLOR_RESET, buf);
}

int main(int argc, char *argv[])
{
	const char* filename = "hello.c";
	printError("cannot open file %s\n", filename);
	printf("this message is printed to stdout\n");
	fatal("cannot open file %s\n", filename);
	printf("this message should not be seen\n");
	return 0;
}
