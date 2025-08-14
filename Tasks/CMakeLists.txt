cmake_minimum_required(VERSION 4.0)
project(Tasks)

set(CMAKE_CXX_STANDARD 20)

add_executable(Tasks main.cpp
        ColaGenerica/ColaGenerica.cpp
        ColaGenerica/ColaGenerica.h)
