cmake_minimum_required (VERSION 3.5)

project(Voxeloo)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_library(${PROJECT_NAME} SHARED)

include(cmake/CPM.cmake)

CPMAddPackage("gh:FlySkyPie/biomes-voxeloo-geometry@0.1.1")
CPMAddPackage("gh:FlySkyPie/biomes-voxeloo-light-kernelry@0.1.2")

# Add sub directories
add_subdirectory(anima)
add_subdirectory(common)
add_subdirectory(biomes)
add_subdirectory(gaia)

target_sources(
    ${PROJECT_NAME}
    PRIVATE
    $<TARGET_OBJECTS:VoxelooAnima>
    $<TARGET_OBJECTS:VoxelooCore>
    $<TARGET_OBJECTS:VoxelooBiomes>
    $<TARGET_OBJECTS:VoxelooGaia>
)