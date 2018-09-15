#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

class TempStdOut
{
	int _saved_stdout;
public:
	explicit TempStdOut(const char* path, const char* mode = "w") {
		std::cout << std::flush;
		_saved_stdout = dup(STDOUT_FILENO);
		if (_saved_stdout < 0) {
			perror("dup");
		}
		FILE* fp = fopen(path, mode);
		if (!fp) {
			perror("fopen");
		}
		int fd = fileno(fp);
		if (dup2(fd, STDOUT_FILENO) < 0) {
			perror("dup2 in ctor");
		}
		close(fd);
	}
	~TempStdOut() {
		std::cout << std::flush;
		if (dup2(_saved_stdout, STDOUT_FILENO) < 0) {
			perror("dup2 in dtor");
		}
	}
};

void log(){
	TempStdOut redirFile("log", "a");
	std::cout << "Hello to file\n"; 
}

int main(int argc, char *argv[])
{
	std::cout << "Hello to terminal\n";
	log();
	std::cout << "Hello to terminal\n";
	return 0;
}
