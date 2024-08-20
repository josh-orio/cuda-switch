cmake_minimum_required(VERSION 3.28.0)
project(cuda-switch)

include(CheckLanguage)
check_language(CUDA)

message(STATUS "CMAKE_CXX_COMPILER = ${CMAKE_CXX_COMPILER}")
message(STATUS "CMAKE_CUDA_COMPILER = ${CMAKE_CUDA_COMPILER}")

if (CMAKE_CUDA_COMPILER) # has a string value and also a bool value? wtf cmake!
    message(STATUS "CUDA found. Compiling with CUDA support.")
    enable_language(CUDA)
    set(CMAKE_CXX_STANDARD 20)
    set_source_files_properties(main.cpp PROPERTIES LANGUAGE CUDA)
    add_executable(exec-cu main.cpp test.cu)
else()
    message(STATUS "CUDA not found. Compiling without CUDA support.")
    enable_language(CXX)
    set(CMAKE_CXX_STANDARD 20)
    add_executable(exec main.cpp)
endif()
