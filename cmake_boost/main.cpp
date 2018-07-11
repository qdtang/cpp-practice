#include <iostream>
#include <string>
#include <boost/regex.hpp>

int main(int argc, char *argv[])
{
	boost::regex pat("^Subject: (Re: |Aw:)*(.*)");
	std::string line;
	while (std::getline(std::cin, line)) {
		boost::smatch matches;
		if (boost::regex_match(line, matches, pat)) {
			std::cout << matches[2] << "\n";
		}
	}

	return 0;
}
