cmake_minimum_required(VERSION 3.0.0)
project(k-nearest_neighbors VERSION 0.1.0)

include_directories(src)

add_subdirectory(src)
add_subdirectory(tst)
add_subdirectory(lib/googletest)
include_directories(lib/googletest/include)