#include <iostream>
#include <dlfcn.h>

typedef double (*algo_func)(size_t, double*);

int main()
{
	void* handle = dlopen("./libalgo.so", RTLD_LAZY);
	algo_func algo = reinterpret_cast<algo_func>(dlsym(handle, "algo_itfc"));
	double arr[] = {3.5, 4.2, 2.8, 9.8, 4.2, 1.4, 2.8};
	std::cout << algo(sizeof(arr)/sizeof(double), arr) << "\n";
	return 0;
}
