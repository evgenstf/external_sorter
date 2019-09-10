cmake_minimum_required(VERSION 2.8.4)
project(file_with_lines)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD_REQUIRED ON)

include_directories(..)
add_subdirectory(../line_view line_view)

add_library(file_with_lines "file_with_lines.cpp" "line_iterator.cpp")

add_executable(file_with_lines_bin "main.cpp")
target_link_libraries(file_with_lines_bin file_with_lines line_view random_access_file)
set_target_properties(file_with_lines_bin PROPERTIES OUTPUT_file file_with_lines)
