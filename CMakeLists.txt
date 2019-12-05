cmake_minimum_required(VERSION 3.10)
project(CubicCrossLinkedOctree)
aux_source_directory(. DIR_SRCS)
include_directories("${PROJECT_SOURCE_DIR}/file_format/ply")
add_subdirectory(file_format/ply)

set(SOURCES main.cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(CubicCrossLinkedOctree ${SOURCES})
target_link_libraries(CubicCrossLinkedOctree PlyFile)