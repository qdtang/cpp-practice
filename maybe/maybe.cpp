#include <iostream>
#include <string>
#include <functional>
using namespace std;

struct Country
{
	string* name = nullptr;
};

struct Address
{
	Country *country = nullptr;
};

struct Person
{
	Address* address = nullptr;
};

template <typename T>
struct Maybe;

template <typename T>
Maybe<T> maybe(T *context) {
	return Maybe<T>{context};
}

template <typename T> 
struct Maybe
{
	T* context;
	Maybe(T *context) : context(context) {}

	template <typename TFunc>
	auto with(TFunc evaluator)
	{
		// will implicitly construct Maybe<remove_pointre_t<invoke_result_t<TFunc, T*>>>
		// with nullptr if context is nullptr.
		auto ret = context != nullptr ? maybe(invoke(evaluator, context)) : nullptr;
		cout << "[Diag]in with: " << boolalpha
			 << is_same<decltype(ret),
						Maybe<remove_pointer_t<invoke_result_t<TFunc, T*>>>>::value
			 << "\n";
		return ret;

	}

	template <typename TFunc>
	auto act(TFunc action)
	{
		if (context != nullptr) action(context);
		return *this;
	}
};

void print_country_name(Person *p)
{
	auto z = maybe(p)
			.with([](auto x) {return x->address;})
			.with([](auto x) {return x->country;})
			.with([](auto x) {return x->name;})
			.act([](auto x) {cout << *x << '\n';});
	cout << "[Diag]in print_country_name: " << boolalpha
		 << is_same<decltype(z), Maybe<string>>::value << "\n";

}

int main(int argc, char *argv[])
{
	cout << "[Diag]testing print_count_name()...\n"; 
	cout << "[Diag]testing with nullptr...\n";
	print_country_name(nullptr);

	cout << "[Diag]testing with empty Persion...\n";
	Person p;
	print_country_name(&p);

	cout << "[Diag]testing with Persion with empty address...\n";
	p.address = new Address{};
	print_country_name(&p);

	cout << "[Diag]testing with Persion with empty country...\n";
	p.address->country = new Country{};
	print_country_name(&p);

	cout << "[Diag]testing with Persion with non-empty country...\n";
	p.address->country->name = new string{"China"};
	print_country_name(&p);

	delete p.address->country->name;
	delete p.address->country;
	delete p.address;
	return 0;
}
