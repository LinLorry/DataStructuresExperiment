cmake_minimum_required(VERSION 3.12)
project(Algorithm)

set(CMAKE_CXX_STANDARD 11)

add_executable(Algorithm include/myhead.h include/myhead.cpp /
        res/LinkStack_main.cpp res/LinkStack/ex4_2_Text.h res/LinkStack/LinkStack.h)