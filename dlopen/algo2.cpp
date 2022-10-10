#include <vector>

double algo2(const std::vector<double>& features)
{
	double ret = 0;
	for (auto d : features) {
		ret -= d;
	}
	return ret;
}

extern "C"
double algo_itfc(size_t count, double* arr);

double algo_itfc(size_t count, double* arr)
{
	std::vector<double> features{arr, arr + count};
	return algo2(features);
}

