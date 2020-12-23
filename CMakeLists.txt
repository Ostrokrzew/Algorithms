cmake_minimum_required(VERSION 3.10)
project(EngineerProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(EngineerProject rng.cpp rng.h utils.h main.cpp headers.h errors.h filenames_generator.h
        table_algorithms_refactored.cpp table_algorithms_refactored.h table_algorithms.cpp table_algorithms.h
        run_algorithms.cpp run_algorithms.h list.h list_algorithms.cpp list_algorithms.h tables_utils.h tree.h)
