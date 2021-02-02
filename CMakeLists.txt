cmake_minimum_required(VERSION 3.10)
project(EngineerProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(EngineerProject rng.h utils.h main.cpp headers.h errors.h filenames_generator.h
		table_algorithms_refactored.cpp table_algorithms_refactored.h table_algorithms.cpp table_algorithms.h
		run_algorithms.cpp run_algorithms.h list.h list_algorithms.cpp list_algorithms.h table.h tree.h
		list_algorithms_refactored.cpp list_algorithms_refactored.h tree_algorithms.cpp tree_algorithms.h tree_algorithms_refactored.cpp tree_algorithms_refactored.h)
