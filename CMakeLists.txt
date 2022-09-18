cmake_minimum_required(VERSION 3.5)

project(drweb_dict LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(drweb_dict dict.h main.cpp)
