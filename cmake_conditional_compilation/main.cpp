#include <iostream>

template <typename T>
void func(T t) {
    std::cout << "from generic template, " << t << "\n";
}

template <>
void func(int t) {
    std::cout << "from specialization, " << t << "\n";
}
 
#ifdef GENERATE_NORMAL_FUNC
void func(int t) {
    std::cout << "from normal function, " << t << "\n";
}
#endif

int main()
{
    func(4.3);
    func(4);
    func<int>(4);
    return 0;
}