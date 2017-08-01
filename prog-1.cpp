#include <iostream>

int main()
{
#ifdef _OPENMP
    std::cout << "Hello, OpenMP!" << std::endl;
#else
    std::cout << "Hello, world!" << std::endl;
#endif
    return 0;
}
