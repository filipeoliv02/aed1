cmake_minimum_required(VERSION 3.12)

project(AED1 C)

set(CMAKE_C_STANDARD 99)

add_executable(AED1
        main.c
        libs_src/lib_stats.c libs_src/lib_stats.h libs_src/lib_util.c libs_src/lib_util.h
        pr00.c pr00.h pr01.c pr01.h)

target_link_libraries(AED1 PRIVATE m)