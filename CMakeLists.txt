cmake_minimum_required(VERSION 3.31)
project(c_code_practice C)

set(CMAKE_C_STANDARD 23)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")


add_executable(c_code_practice main2.c
        modern-c-features/modern_c.c
        allocators/linearallocator.h)

