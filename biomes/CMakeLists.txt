# Set the project name
project (VoxelooBiomes)

# Add a library with the above sources
add_library(${PROJECT_NAME}
    OBJECT
    biomes.cpp
    culling.cpp
    noise.cpp
    shards.cpp)

include(../cmake/CPM.cmake)

set(CEREAL_BUILD_DOC OFF)
set(EIGEN_BUILD_DOC OFF)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

CPMAddPackage("gh:FlySkyPie/biomes-voxeloo-geometry@0.1.1")
CPMAddPackage("gh:catchorg/Catch2@2.13.10")
CPMAddPackage("gh:USCiLab/cereal@1.3.2")
CPMAddPackage("gl:libeigen/eigen#3.4.0")
CPMAddPackage("gh:martinus/robin-hood-hashing#3.11.5")
CPMAddPackage("gh:FlySkyPie/OpenSimplexNoise@1.0.2")

# target_link_libraries(${PROJECT_NAME} PRIVATE VoxelooGeometry)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    VoxelooGeometry
    Catch2
    cereal::cereal
    robin_hood::robin_hood
    Eigen3::Eigen
    OpenSimplexNoise)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC 
    ${PROJECT_SOURCE_DIR}/../include
)
