cmake_minimum_required(VERSION 3.12)
project(Algorithm)

set(CMAKE_CXX_STANDARD 11)

add_executable(Algorithm include/myhead.h include/myhead.cpp
        res/LinkQueue_main.cpp res/LinkQueue/LinkQueue.h res/LinkQueue/ex5_2_Text.h res/LinkQueue/ParkSystem.cpp res/LinkQueue/ParkSystem.h res/Models/Car.cpp res/Models/Car.h res/Models/ParkingCar.cpp res/Models/ParkingCar.h res/LinkQueue/CarQueue.cpp res/LinkQueue/CarQueue.h)