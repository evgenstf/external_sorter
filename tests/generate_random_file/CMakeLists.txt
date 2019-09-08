cmake_minimum_required(VERSION 2.8.4)
project(generate_random_file)
set(CMAKE_CXX_STANDARD 17)

add_library(generate_random_file "generate_random_file.cpp")

add_executable(generate_random_file_bin "main.cpp")
target_link_libraries(generate_random_file_bin generate_random_file)
set_target_properties(generate_random_file_bin PROPERTIES OUTPUT_file generate_random_file)
