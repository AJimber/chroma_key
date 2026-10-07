cmake_minimum_required(VERSION 3.10)

project(chroma_key VERSION 1.4.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS_DEBUG "-ggdb3 -O0 -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "-g -O3 -Wall")

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(chroma_key
    chroma_key.cpp
    common_code.cpp
    common_code.hpp
)

target_link_libraries(chroma_key ${OpenCV_LIBS})