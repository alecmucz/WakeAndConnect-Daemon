cmake_minimum_required(VERSION 3.28)
project(WakeandConnect)

set(CMAKE_CXX_STANDARD 17)

add_executable(WakeandConnect main.cpp
        include/network.h
        src/network.cpp
        include/protocols.h
        src/protocols.cpp
        include/server_config.h
        src/server_config.cpp)
