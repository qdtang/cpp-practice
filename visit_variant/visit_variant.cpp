#include <iostream>
#include <variant>
#include <string>
#include <type_traits>

struct Visitor
{
   void operator()(const int& i) {std::cout << "int with value " << i << "\n";}
   void operator()(const double& d) {std::cout << "double with value " << d << "\n";}
   void operator()(const std::string& s) {std::cout << "string with value " << s << "\n";}
};

template <typename... Ts>
struct overloaded : Ts...
{
	using Ts::operator()...;
};
// deduction guide (since C++17)
template <typename... Ts> overloaded(Ts...) -> overloaded<Ts...>;

int main()
{
    using Var =  std::variant<int, double, std::string>;
    auto visitor = [](const auto& t){
        using T = std::decay_t<decltype(t)>;
        std::cout << "from lambda: ";
        if constexpr (std::is_same_v<T, int>) {
            std::cout << "int with value " << t << "\n";
        }
        else if constexpr (std::is_same_v<T, double>) {
            std::cout << "double with value " << t << "\n";
        }
        else if constexpr (std::is_same_v<T, std::string>) {
            std::cout << "string with value " << t << "\n";
        }
    };

	auto ol = overloaded{
		[](int i){std::cout << "int from overloaded: " << i << "\n";},
		[](double d){std::cout << "double from overloaded: " << d << "\n";},
		[](const std::string& s){std::cout << "string from overloaded: " << s << "\n";}
	};

    std::visit(Visitor(), Var{"hello"});
    std::visit(Visitor(), Var{7});
    std::visit(Visitor(), Var{7.0});
    std::visit(visitor, Var{"world"});
    std::visit(visitor, Var{8});
    std::visit(visitor, Var{8.8});
	std::visit(ol, Var{233});
	std::visit(ol, Var{2.33});
    return 0;
}
