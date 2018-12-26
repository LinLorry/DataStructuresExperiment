cmake_minimum_required(VERSION 3.12)
project(Algorithm)

set(CMAKE_CXX_STANDARD 11)

add_executable(Algorithm include/myhead.h include/myhead.cpp /
        res/SqQueue_main.cpp res/SqQueue/SqQueue.h res/SqQueue/ex5_1_Text.h)