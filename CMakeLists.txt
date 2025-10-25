cmake_minimum_required (VERSION 3.5)

project(Voxeloo)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_library(${PROJECT_NAME} SHARED)

include(cmake/CPM.cmake)

CPMAddPackage("gh:FlySkyPie/biomes-voxeloo-geometry@0.1.1")
CPMAddPackage("gh:FlySkyPie/biomes-voxeloo-light-kernelry@0.1.2")

# Add sub directories
add_subdirectory(src/anima)
add_subdirectory(src/common)
add_subdirectory(src/biomes)
add_subdirectory(src/gaia)
add_subdirectory(src/mapping)
add_subdirectory(src/tensors)

target_sources(
    ${PROJECT_NAME}
    PRIVATE
    $<TARGET_OBJECTS:VoxelooAnima>
    $<TARGET_OBJECTS:VoxelooCore>
    $<TARGET_OBJECTS:VoxelooBiomes>
    $<TARGET_OBJECTS:VoxelooGaia>
    $<TARGET_OBJECTS:VoxelooMapping>
    $<TARGET_OBJECTS:VoxelooTensors>
)