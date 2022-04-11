cmake_minimum_required(VERSION 3.21)
project(matrix_cal_b)

set(CMAKE_CXX_STANDARD 14)

include_directories(sources)

add_executable(matrix_cal_b
        doctest.h
        sources/Matrix.cpp
        sources/Matrix.hpp
        Main.cpp
        Test.cpp
        TestRunner.cpp)
