cmake_minimum_required(VERSION 2.8)
project(project2)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Event.cpp Event.h Passenger.cpp Passenger.h Scenario.cpp Scenario.h Simulation.cpp Simulation.h)
add_executable(project2 ${SOURCE_FILES})
