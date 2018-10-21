#include <iostream>
#include <tuple>
#include <type_traits>

using namespace std;

template <typename Tuple1, typename Tuple2, typename Target>
struct remove_type_impl;

template <typename... TupleMem, typename Head, typename... Tails, typename Target>
struct remove_type_impl<tuple<TupleMem...>, tuple<Head, Tails...>, Target>
{
    using type = typename remove_type_impl<tuple<TupleMem..., Head>, tuple<Tails...>, Target>::type;
};

template <typename... TupleMem, typename... Tails, typename Target>
struct remove_type_impl<tuple<TupleMem...>, tuple<Target, Tails...>, Target>
{
    using type = typename remove_type_impl<tuple<TupleMem...>, tuple<Tails...>, Target>::type;
};

template <typename... TupleMem, typename Head, typename Target>
struct remove_type_impl<tuple<TupleMem...>, tuple<Head>, Target>
{
    using type = tuple<TupleMem..., Head>;
};

template <typename... TupleMem, typename Target>
struct remove_type_impl<tuple<TupleMem...>, tuple<Target>, Target>
{
    using type = tuple<TupleMem...>;
};

template <typename Tuple, typename Target>
struct remove_type : remove_type_impl<tuple<>, Tuple, Target> {};

template <typename Target>
struct remove_type<tuple<>, Target>
{
    using type = tuple<>;
};

template <typename Tuple, typename Target>
using remove_type_t = typename remove_type<Tuple, Target>::type;

int main()
{
    static_assert (is_same_v<
                   remove_type_t<tuple<int, double, float>, int>,
                   tuple<double, float>
                   >, "");
    static_assert (is_same_v<
                   remove_type_t<tuple<double, float, int>, int>,
                   tuple<double, float>
                   >, "");
    static_assert (is_same_v<
                   remove_type_t<tuple<double, int, float, int>, int>,
                   tuple<double, float>
                   >, "");
    static_assert (is_same_v<
                   remove_type_t<tuple<double, float>, int>,
                   tuple<double, float>
                   >, "");
    static_assert (is_same_v<
                   remove_type_t<tuple<>, int>,
                   tuple<>
                   >, "");
    return 0;
}
