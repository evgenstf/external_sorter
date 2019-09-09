cmake_minimum_required(VERSION 2.8.4)
project(temporary_file)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD_REQUIRED ON)

include_directories(..)
add_subdirectory(../random_access_file random_access_file)

add_executable(temporary_file_bin "main.cpp")
target_link_libraries(temporary_file_bin random_access_file)
set_target_properties(temporary_file_bin PROPERTIES OUTPUT_file temporary_file)
