// This program is ill-formed (due to variable "ill_formed") and 
// compiler would print out prime numbers up to LAST in error message.

template <int p, int i>
struct is_prime_impl
{
	static constexpr bool value = (p % i) && is_prime_impl<p, i-1>::value;
};

template <int p>
struct is_prime_impl<p, 1>
{
	static constexpr bool value = true;
};

template <int p>
struct is_prime : is_prime_impl<p, p-1> {};

template <>
struct is_prime<1>
{
	static constexpr bool value = false;
};

// C++14 supports variable templates
template <int p>
constexpr bool is_prime_v = is_prime<p>::value;

template <int p, bool>
struct print_prime_impl
{
	// recursion happens due to this member,
	// template specialization for every number until explicit specialization
	print_prime_impl<p-1, is_prime_v<p-1>> np;
};

template <int p>
struct prime_number {};

// partial specialization for prime numbers
template <int p>
struct print_prime_impl<p, true>
{
	print_prime_impl<p-1, is_prime_v<p-1>> np;
	// only prime number has this ill-formed variable,
	// thus printed out by compiler
	int ill_formed = prime_number<p>::value;
};

// explicit specialization to stop the recursion
template <>
struct print_prime_impl<1, false> {};

template <int p>
struct print_prime : print_prime_impl<p, is_prime_v<p>> {};

#ifndef LAST
#define LAST 10
#endif

int main(int argc, char *argv[])
{
	// trigger the specialization
	print_prime<LAST> a;
	return 0;
}