cmake_minimum_required(VERSION 3.12)
project(Algorithm)

set(CMAKE_CXX_STANDARD 11)

add_executable(Algorithm include/myhead.h include/myhead.cpp /
                res/DoubleLinkList_main.cpp res/DoubleLinkList/DoubleLinkList.h res/DoubleLinkList/ex3_4_Text.h res/DoubleLinkList/MyDoubleLinkList.h)