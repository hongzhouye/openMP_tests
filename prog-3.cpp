#include <iostream>
#include <omp.h>
#include <vector>
#include <cmath>
#include <cassert>

int main()
{
    const int size = 10000;
    std::vector<double> a(size, 0.);
    double x = 0.;

    double start = omp_get_wtime();
#pragma omp parallel reduction(+:x)  // create threads
{
#pragma omp for         // assign threads to for loop
    for(size_t i = 0; i < size; i++)
    {
        for(size_t j = 0; j < size; j++)
            a[i] += 1. / sqrt(sqrt(i + j + 1.));
        x += a[i];
    }
}
    double stop = omp_get_wtime();
    std::cout << "x = " << x << std::endl;
    std::cout << "wall time: " << stop - start << " sec" << std::endl;

    double sum = 0.;
    for(size_t i = 0; i < size; i++)    sum += a[i];

    std::cout << "sum = " << sum << std::endl;

    assert(fabs ((sum - x) / x) < 1.E-10);

    return 0;
}
