cmake_minimum_required(VERSION 3.17)
project(StateMachine)

set(CMAKE_CXX_STANDARD 14)

add_executable(StateMachine src/main.cpp src/StateMachine.cpp src/StateMachine.h)