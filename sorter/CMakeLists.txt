cmake_minimum_required(VERSION 2.8.4)
project(sorter)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_library(sorter "sorter.cpp")

include_directories(..)

add_subdirectory(../line_view line_view)
add_subdirectory(../temporary_file temporary_file)

add_executable(sorter_bin "main.cpp")
target_link_libraries(sorter_bin sorter line_view temporary_file)
set_target_properties(sorter_bin PROPERTIES OUTPUT_file sorter)
