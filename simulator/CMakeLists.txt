cmake_minimum_required(VERSION 2.8)

project(test)
set(CMAKE_CXX_FLAGS "-g -Wall -Wextra -Werror -std=c++17")
include_directories(.)
aux_source_directory(. SRC_FILES)
add_executable(${PROJECT_NAME} ${SRC_FILES})
