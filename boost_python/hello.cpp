#include <iostream>
#include <boost/python.hpp>

void hello()
{
	std::cout << "hello, boost python.\n";
}

BOOST_PYTHON_MODULE(hello)
{
	boost::python::def("hello", hello);
}
