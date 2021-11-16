cmake_minimum_required(VERSION 3.17)
project(deep_dive_in_algorithms)

set(CMAKE_CXX_STANDARD 14)

add_executable(deep_dive_in_algorithms
        divide-conquer-algorithms/inversion-counts/main.cpp
        divide-conquer-algorithms/quicksort/main.cpp)
