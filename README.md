# Cuda Switch

Sometimes I want to compile my code on a Mac, othertimes on a server with an NVIDIA GPU.

## How it works

**CMake**

- CMake looks for an installation of CUDA
- If CUDA is found:
    * CUDA is enabled
    * CPP standard is set to 20 (defaults to 17)
    * .cpp file is declared as CUDA source (meaning nvcc will compile it, not g**)
    * .cu file is linked
    * Compilation is done
- Else:
    * CPP (20) is enabled
    * Compilation is done without GPU functions

**CPP**

- When compiled with nvcc, the \_\_CUDACC\_\_ macro will be defined
- This allows branching using #ifdef and #ifndef
- Easy way to select between using a CPU or GPU function :)

## Build

```bash
git clone https://github.com/josh-orio/cuda-switch.git
cd cuda-switch
mkdir build
cd build
cmake ..
make
```