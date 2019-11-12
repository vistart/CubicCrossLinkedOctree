cmake_minimum_required(VERSION 3.10)
project(CubicCrossLinkedOctree)

include_directories("file_format/ply")

set(SOURCES main.cpp "file_format/ply/ply.c" "file_format/ply/vertex.cpp")

set(CMAKE_CXX_STANDARD 17)

add_executable(CubicCrossLinkedOctree ${SOURCES})
