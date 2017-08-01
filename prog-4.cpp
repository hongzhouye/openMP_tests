#include <iostream>
#include <omp.h>
#include <vector>
#include <cmath>


double two_body_energy(int i, int j)
{
    return (i + j) / 10.;
}

int main()
{
    const int nbodies = 50000;
    double energy = 0.;

    double start = omp_get_wtime();

/*
#pragma omp parallel for reduction(+:energy) schedule(static)
    for(size_t i = 0; i < nbodies; i++)
    for(size_t j = i + 1; j < nbodies; j++)
        energy += two_body_energy(i, j);
*/

/*
#pragma omp parallel for
    for(size_t i = 0; i < nbodies; i++)
    for(size_t j = i + 1; j < nbodies; j++)
#pragma omp atomic
        energy += two_body_energy(i, j);
*/

#pragma omp parallel
{
    #pragma omp for
    for(size_t i = 0; i < nbodies; i++)
    for(size_t j = i + 1; j < nbodies; j++)
    {
        double eij = two_body_energy(i, j);
        #pragma omp atomic
        energy += eij;
    }
}

    std::cout << "energy = " << energy << std::endl;

    double end = omp_get_wtime();
    std::cout << "wall time = " << end - start << " sec" << std::endl;

    return 0;
}
