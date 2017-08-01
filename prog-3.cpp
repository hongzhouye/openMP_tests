#include <iostream>
#include <omp.h>
#include <vector>
#include <cmath>

int main()
{
    const int size = 20000;
    std::vector<double> a(size, 0.);

    double start = omp_get_wtime();
#pragma omp parallel for
        for(size_t i = 0; i < size; i++)
        {
            a[i] = 0.;
            for(size_t j = 0; j < size; j++)
                a[i] += sqrt(sqrt(i + j));
        }
    double stop = omp_get_wtime();
    std::cout << "wall time: " << stop - start << " sec" << std::endl;

    return 0;
}
