#include <iostream>
#include <string>
#include <sstream>
#include <any>
#include <experimental/filesystem>
#include <thread>
#include <boost/regex.hpp>

namespace fs = std::experimental::filesystem;

int main()
{
	// test any
	std::any a = 17;
	std::cout << std::any_cast<int>(a) << "\n";
	// test filesystem
	std::cout << fs::current_path() << "\n";
	// test thread
	std::cout << std::this_thread::get_id() << "\n";

    // test boost::regex
    std::string line;
    boost::regex pat("^Subject: (Re: |Aw: )*(.*)");
    std::stringstream ss;
    ss << "Subject: Boost has been compiled correctly.\n";
    ss << "See Subject.\n";
    while (ss)
    {
        std::getline(ss, line);
        boost::smatch matches;
        if (boost::regex_match(line, matches, pat))
            std::cout << matches[2] << std::endl;
    }

    return 0;
}

