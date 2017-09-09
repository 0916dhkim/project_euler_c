cmake_minimum_required(VERSION 3.5)
project(project_euler_solution)

set(CMAKE_C_STANDARD 99)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_library(number_theory src/number_theory/number_theory.c)
target_include_directories(number_theory PUBLIC src/number_theory)

add_executable(prob_1 src/1/main.c)
target_link_libraries(prob_1 number_theory)

add_executable(prob_2 src/2/main.c)

add_executable(prob_3 src/3/main.c)

add_executable(prob_4 src/4/main.c)
