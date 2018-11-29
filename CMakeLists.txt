cmake_minimum_required(VERSION 3.12)
project(Algorithm)

set(CMAKE_CXX_STANDARD 11)

add_executable(Algorithm res/LinkList_main.cpp /
                        res/LinkList/LinkList.h res/LinkList/MyLinkList.h /
                        res/LinkList/Term_LinkList.cpp res/LinkList/Term_LinkList.h /
                        res/LinkList/ex3_2_Text.h /
                        res/Models/Term.cpp res/Models/Term.h include/myhead.cpp)