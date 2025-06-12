cmake_minimum_required(VERSION 3.31)
project(c_code_practice C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

include_directories(${CMAKE_SOURCE_DIR}/Unity/src)

add_library(unity STATIC Unity/src/unity.c)

add_executable(c_code_practice
        modern-c-features/modern_c.c
        allocators/linearallocator.h
        main.c)

target_link_libraries(c_code_practice PRIVATE unity)