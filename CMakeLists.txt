cmake_minimum_required(VERSION 3.21)
project(web_server)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)


add_executable(web_server Thread/setitimer.cpp Thread/timer.cpp Thread/stdthread.cpp Thread/pthread_condition.cpp Thread/semaphore.cpp net/select.cpp net/netAPI.cpp net/server.cpp net/poll.cpp net/epoll.cpp)
