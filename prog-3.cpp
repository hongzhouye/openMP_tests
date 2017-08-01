#include <iostream>
#include <omp.h>
#include <vector>
#include <cmath>

int main()
{
    const int size = 20000;
    std::vector<double> a(size, 0.);
    int x = -1;

    double start = omp_get_wtime();
#pragma omp parallel    // create threads
{
    x = omp_get_thread_num() + 100;
#pragma omp for
    for(size_t i = 0; i < size; i++)
    {
        for(size_t j = 0; j < size; j++)
            a[i] += sqrt(sqrt(i + j));
    }
}
    double stop = omp_get_wtime();
    std::cout << "x = " << x << std::endl;
    std::cout << "wall time: " << stop - start << " sec" << std::endl;

    return 0;
}
