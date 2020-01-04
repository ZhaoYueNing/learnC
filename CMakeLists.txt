cmake_minimum_required(VERSION 3.15)
project(learnC C)

set(CMAKE_C_STANDARD 11)

add_library(learnC list.c list.h)

# add_executable(learnC list.c list.h main.c)