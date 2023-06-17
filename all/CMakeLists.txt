# This file is for IDEs

cmake_minimum_required(VERSION 3.14...3.22)

project(BuildAll LANGUAGES CXX)

# needed to generate test target
enable_testing()

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/../main ${CMAKE_BINARY_DIR}/main)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/../tests ${CMAKE_BINARY_DIR}/tests)