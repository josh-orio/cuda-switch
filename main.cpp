#include <iostream>

int main() {
    std::cout << "Hi" << std::endl;

    #ifdef __CUDACC__
        std::cout << "CUDA supported" << std::endl;
        #include "test.cuh"
    #else
        std::cout << "CUDA not supported" << std::endl;
    #endif

    return 0;
}
