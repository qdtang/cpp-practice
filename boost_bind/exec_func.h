#ifndef __EXEC_FUNC_H__
#define __EXEC_FUNC_H__
#include <boost/function.hpp>
#include <vector>
typedef boost::function<int ()> PF;
void execFunctions(const std::vector<PF>& PFs);
#endif //__EXEC_FUNC_H__ 
