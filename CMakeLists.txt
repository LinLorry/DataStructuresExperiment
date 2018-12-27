cmake_minimum_required(VERSION 3.12)
project(Algorithm)

set(CMAKE_CXX_STANDARD 11)

add_executable(Algorithm include/myhead.h include/myhead.cpp
        res/Sorting_main.cpp res/Sorting/SortingExperiment.cpp res/Sorting/SortingExperiment.h)