#include <iostream>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

int main()
{
    std::cout << fs::current_path() << "\n";
    fs::create_directory("./fs");
    return 0;
}
