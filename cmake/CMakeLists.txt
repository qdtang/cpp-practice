cmake_minimum_required(VERSION 2.6)

project(demo)
set(CMAKE_CXX_FLAGS "\
		-std=c++17 \
		-Wall \
		-Wextra \
		-Werror \
	")

message(STATUS "Starting cmake")

if(NOT CMAKE_BUILD_TYPE)
    message(STATUS "Making Debug build")
    set(CMAKE_BUILD_TYPE Debug)
elseif(CMAKE_BUILD_TYPE STREQUAL Release)
    message(STATUS "Making Release build")
elseif(CMAKE_BUILD_TYPE STREQUAL RelWithDebInfo)
    message(STATUS "Making RelWithDebInfo build")
elseif(CMAKE_BUILD_TYPE STREQUAL MinSizeRel)
    message(STATUS "Making MinSizeRel build")
endif()

add_subdirectory(lib1)
include_directories(lib1)
aux_source_directory(. ROOT_SRC)
add_executable(${PROJECT_NAME} ${ROOT_SRC})
target_link_libraries(${PROJECT_NAME} hello)
message(STATUS "Finishing cmake")

