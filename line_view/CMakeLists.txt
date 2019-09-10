cmake_minimum_required(VERSION 2.8.4)
project(line_view)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD_REQUIRED ON)

include_directories(..)
add_subdirectory(../random_access_file random_access_file)

add_library(line_view "line_view.cpp")

add_executable(line_view_bin "main.cpp")
target_link_libraries(line_view_bin line_view random_access_file)
set_target_properties(line_view_bin PROPERTIES OUTPUT_file line_view)
