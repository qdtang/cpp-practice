#include <boost/bind.hpp>
#include <vector>
#include "exec_func.h"

static int add(int a, int b)
{
	return a + b;
}

int main(int argc, char *argv[])
{
	std::vector<PF> PFs;
	PFs.push_back(boost::bind(add, 1, 4));
	PFs.push_back(boost::bind(add, 9, 5));
	PFs.push_back(boost::bind(add, 7, 8));
	execFunctions(PFs);
	return 0;
}
