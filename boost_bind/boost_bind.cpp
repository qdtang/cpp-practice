#include <iostream>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <vector>

int add(int a, int b)
{
	return a + b;
}

typedef boost::function<int ()> PF;

void execFunctions(const std::vector<PF>& PFs)
{
	for (std::vector<PF>::const_iterator iter = PFs.begin(); iter != PFs.end(); ++iter) {
		std::cout << (*iter)() << '\n';
	}
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
