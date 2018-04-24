cmake_minimum_required(VERSION 2.8)

project(asynccompute)
add_executable(${PROJECT_NAME} "asynccompute.cpp")
target_link_libraries(${PROJECT_NAME} pthread)
