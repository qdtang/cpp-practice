#include <iostream>
#include <tuple>

template <typename T, typename U> 
class bar
{
    public:
        void operator()() {std::cout<<"base"<<std::endl;}
};

template <
    template <typename...> class T, typename... TArgs,
    template <typename...> class U, typename... UArgs
    >
class bar<T<TArgs...>, U<UArgs...>>
{
    public:
        void operator()() {std::cout<<"spec"<<std::endl;}
        void method(TArgs... targs, UArgs... uargs) {std::cout<<sizeof...(targs)<<" "<<sizeof...(uargs)<<std::endl;}
};

int main(int argc, char** argv)
{
    bar<std::tuple<int, char>, std::tuple<float>> b;
    b();
    b.method(1, 'a', 0.2);
	return 0;
}
