#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <array>
#include <list>
#include <forward_list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

template <class C>
concept asso_container = requires {
    typename C::key_type;
    typename C::mapped_type;
};

template <class C>
concept has_value_type = requires {
        typename C::value_type;
};

template <class C>
concept seq_container = has_value_type<C> && !asso_container<C>;

template <class T>
concept printable = requires (T v) {
        std::cout << v;
};

template <class K, class V, template <class, class, class...> class Container, class... Args>
requires asso_container<Container<K,V, Args...>> && printable<K> && printable<V>
void print(const Container<K,V, Args...>& c, const char* delim = " ")
{
    for (const auto& p : c) {
        std::cout << p.first << ":" << p.second << delim;
    }
    std::cout << std::endl;
}

template <class T, template <class, class...> class Container, class... Args>
requires seq_container<Container<T, Args...>> && printable<T>
void print(const Container<T, Args...>& c, const char* delim = " ")
{
    std::copy(std::cbegin(c), std::cend(c),
        std::ostream_iterator<typename Container<T, Args...>::value_type>(std::cout, delim));
    std::cout << std::endl;
}

// specialization for array.
template <class T, unsigned long int N>
requires printable<T>
void print(const std::array<T, N>& arr, const char* delim = " ")
{
    std::copy(std::cbegin(arr), std::cend(arr),
        std::ostream_iterator<T>(std::cout, delim));
    std::cout << std::endl;
}

class Int
{
    int a = 0;
public:
        explicit Int(int i) : a(i) {}
        Int() {}
        friend std::ostream& operator<< (std::ostream& out, const Int& i);
};
std::ostream& operator<<(std::ostream& out, const Int& i)
{
        return out << i.a;
}

int main()
{
    std::string str{"hello, world"};
    print(str, "");
    std::vector<double> v{2.4, 9.3, 0.3, 8.4};
    print(v);
    std::vector<Int> vi{Int{93}, Int{42}, Int{}, Int{4}};
    print(vi);
    std::deque<int> d{3, 9, 4, 0, -1};
    print(d);
    std::array<int, 3> a{9, 4, 7};
    print(a);
    std::list<char> l{'r', 'u', 'l', 'e'};
    print(l);
    std::forward_list<int> f{83, 42, 21, 97};
    print(f);
    std::set<int> s{83, 92, 40, 48, 21, 34, 39, 72};
    print(s);
    std::unordered_set<int> us{83, 92, 40, 48, 21, 34, 39, 72};
    print(us);
    std::map<int, std::string> m{{3, "three"}, {4, "four"}, {0, "zero"}};
    print(m);
    std::unordered_map<int, std::string> um{{3, "three"}, {4, "four"}, {0, "zero"}};
    print(um);
    return 0;
}
