#include <boost/python.hpp>
#include "hello.h"

BOOST_PYTHON_MODULE(hello)
{
	boost::python::def("hello", hello);
}
