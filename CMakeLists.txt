cmake_minimum_required (VERSION 3.5)

project(Voxeloo)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_library(${PROJECT_NAME} SHARED src/voxeloo.cpp)

include(cmake/CPM.cmake)

CPMAddPackage("gh:FlySkyPie/biomes-voxeloo-geometry@0.1.1")
CPMAddPackage("gh:FlySkyPie/biomes-voxeloo-light-kernelry@0.1.3")

# Add sub directories
add_subdirectory(src/anima)
add_subdirectory(src/common)
add_subdirectory(src/biomes)
add_subdirectory(src/gaia)
add_subdirectory(src/mapping)
add_subdirectory(src/tensors)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    "$<LINK_LIBRARY:WHOLE_ARCHIVE,VoxelooAnima>"
    "$<LINK_LIBRARY:WHOLE_ARCHIVE,VoxelooCore>"
    "$<LINK_LIBRARY:WHOLE_ARCHIVE,VoxelooBiomes>"
    "$<LINK_LIBRARY:WHOLE_ARCHIVE,VoxelooGaia>"
    "$<LINK_LIBRARY:WHOLE_ARCHIVE,VoxelooMapping>"
    "$<LINK_LIBRARY:WHOLE_ARCHIVE,VoxelooTensors>"
)

# set_target_properties(${PROJECT_NAME} PROPERTIES CXX_VISIBILITY_PRESET "hidden")

enable_testing()
add_subdirectory(tests/biomes)
add_subdirectory(tests/common)
add_subdirectory(tests/gaia)
add_subdirectory(tests/galois)