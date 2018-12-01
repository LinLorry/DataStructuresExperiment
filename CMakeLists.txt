cmake_minimum_required(VERSION 3.12)
project(Algorithm)

set(CMAKE_CXX_STANDARD 11)

add_executable(Algorithm include/myhead.h include/myhead.cpp /
                res/CircularLinkList_main.cpp /
                res/CircularLinkList/CircularLinkList.h /
                res/CircularLinkList/MyCircularLinkList.h /
                res/CircularLinkList/ex3_3_Text.h)