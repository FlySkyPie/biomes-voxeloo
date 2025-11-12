# Set the project name
project (VoxelooAnima)

# Add a library with the above sources
add_library(${PROJECT_NAME}
    OBJECT
    find_surfaces.cpp)

include(../../cmake/CPM.cmake)

CPMAddPackage("gh:FlySkyPie/biomes-voxeloo-geometry@0.1.1")
CPMAddPackage("gh:USCiLab/cereal@1.3.2")

target_link_libraries(${PROJECT_NAME} PRIVATE VoxelooGeometry)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    cereal::cereal)


target_include_directories(
    ${PROJECT_NAME}
    PUBLIC 
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/../../include
)
