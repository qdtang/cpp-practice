cmake_minimum_required(VERSION 3.5)

project(test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall \
		            -Wextra \
					-Werror \
					-g \
					")

add_executable(test main.cpp)
# "cmake .. -DFUNC=OFF" to turn it off
option(FUNC "whether to generate normal function" ON)
if (FUNC)
    add_definitions(-DGENERATE_NORMAL_FUNC)
endif()
