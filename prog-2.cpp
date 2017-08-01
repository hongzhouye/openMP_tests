#include <iostream>
#include <sstream>
#include <omp.h>
#include <cstdio>

int main()
{
#pragma omp parallel
    {
        std::stringstream ss;
        ss << "TID: " << omp_get_thread_num() <<
            " OpenMP will use " << omp_get_max_threads() <<
            " threads" << std::endl;
        std::cout << ss.str();
    }
#pragma omp parallel
    {
        printf("hello from thread %d of %d\n",
            omp_get_thread_num(), omp_get_max_threads());
    }
    return 0;
}
