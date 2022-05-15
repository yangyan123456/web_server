cmake_minimum_required(VERSION 3.21)
project(web_server)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)


add_executable(web_server Processe/setitimer.cpp Processe/timer.cpp Processe/stdthread.cpp)
