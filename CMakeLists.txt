cmake_minimum_required(VERSION 3.12)
project(Algorithm)

set(CMAKE_CXX_STANDARD 11)

add_executable(Algorithm include/myhead.h include/myhead.cpp /
        res/SqStack_main.cpp / res/SqStack/ex4_1_Text.h res/SqStack/SqStack.h /
        res/SqStack/Expression_SqStack.cpp res/SqStack/Expression_SqStack.h)