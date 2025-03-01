cmake_minimum_required(VERSION 3.29)
project(tp_solo C)

set(CMAKE_C_STANDARD 11)

add_executable(tp_solo main.c
        util.h
        util.c
        terrain.h
        terrain.c)
