#include <iostream>
#include "exec_func.h"

void execFunctions(const std::vector<PF>& PFs)
{
	for (std::vector<PF>::const_iterator iter = PFs.begin(); iter != PFs.end(); ++iter) {
		std::cout << (*iter)() << '\n';
	}
}
