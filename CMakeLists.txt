cmake_minimum_required(VERSION 3.30)
project(aoc2024 C)

set(CMAKE_C_STANDARD 11)

add_executable(aoc2024 src/day1.c)

set_target_properties(aoc2024 PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")