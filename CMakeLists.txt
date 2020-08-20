cmake_minimum_required(VERSION 3.13)
project(CubicCrossLinkedOctree)
aux_source_directory(. DIR_SRCS)
include_directories("${PROJECT_SOURCE_DIR}/file_format/PointCloudBasePresentation")
include_directories("${PROJECT_SOURCE_DIR}/file_format/ply")
include_directories("${PROJECT_SOURCE_DIR}/octree")

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "RelWithDebInfo")
    message(
            STATUS "No CMAKE_BUILD_TYPE selected, defaulting to ${CMAKE_BUILD_TYPE}"
    )
endif()

add_compile_options(-D_DEBUG)
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options(-D_DEBUG)
    message(
            STATUS "MARCO '-DEBUG' enabled."
    )
else()
    message(
            STATUS "MARCO '-DEBUG' disabled."
    )
endif()

add_subdirectory(file_format/PointCloudBasePresentation)
add_subdirectory(file_format/ply)
add_subdirectory(octree)

set(SOURCES main.cpp)

set(CMAKE_CXX_STANDARD 17)
target_compile_features(PointCloudBasePresentation PUBLIC cxx_std_17)
target_compile_features(octree PUBLIC cxx_std_17)

add_executable(CubicCrossLinkedOctree ${SOURCES})
target_link_libraries(CubicCrossLinkedOctree PointCloudBasePresentation)
target_link_libraries(CubicCrossLinkedOctree PlyFile)
target_link_libraries(CubicCrossLinkedOctree octree)
