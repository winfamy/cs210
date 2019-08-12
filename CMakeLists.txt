cmake_minimum_required(VERSION 3.14)
project(c)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -o a.out")

add_executable(c pex0/pex0.c)