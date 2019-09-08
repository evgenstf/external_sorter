cmake_minimum_required(VERSION 2.8.4)
project(temporary_file)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_library(temporary_file "temporary_file.cpp")

add_executable(temporary_file_bin "main.cpp")
target_link_libraries(temporary_file_bin temporary_file)
set_target_properties(temporary_file_bin PROPERTIES OUTPUT_file temporary_file)
