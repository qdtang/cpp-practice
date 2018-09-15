#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int fd = open("log", O_WRONLY | O_CREAT);
	if (dup2(fd, STDOUT_FILENO) < 0) {
		perror("dup2");
	}
	std::cout << "Hello\n";
	close(fd);
	return 0;
}
