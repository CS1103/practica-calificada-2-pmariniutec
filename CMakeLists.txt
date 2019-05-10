cmake_minimum_required(VERSION 3.14)
project(PC2)

set(CMAKE_CXX_STANDARD 14)

add_executable(PC2 main.cpp fight.h arena.h arena.cpp fighter.h attacks.h)
