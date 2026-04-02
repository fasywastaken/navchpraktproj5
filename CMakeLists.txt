cmake_minimum_required(VERSION 4.0)
project(navchprakt5)

set(CMAKE_CXX_STANDARD 20)

add_executable(navchprakt5 main.cpp
        destination.cpp
        destination.h
        utility.cpp
        utility.h
        train.cpp
        train.h
        dijikstra.cpp
        dijikstra.h)
