cmake_minimum_required (VERSION 3.5)

project(VoxelooPy)

# set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CEREAL_BUILD_DOC OFF)
set(EIGEN_BUILD_DOC OFF)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

include(../cmake/CPM.cmake)

CPMAddPackage("gh:pybind/pybind11@2.9.2")
CPMAddPackage("gh:USCiLab/cereal@1.3.2")
CPMAddPackage("gh:FlySkyPie/biomes-voxeloo-geometry@0.1.1")
CPMAddPackage("gh:FlySkyPie/biomes-voxeloo-light-kernelry@0.1.3")
CPMAddPackage("gh:martinus/robin-hood-hashing#3.11.5")
CPMAddPackage("gh:FlySkyPie/OpenSimplexNoise@1.0.2")
CPMAddPackage("gh:FlySkyPie/tomasakeninemoeller@1.0.0")
CPMAddPackage("gl:libeigen/eigen#3.4.0")

find_package(pybind11 REQUIRED)

pybind11_add_module(${PROJECT_NAME}
    src/biomes.cpp
    src/blocks.cpp
    src/culling.cpp
    src/ext.cpp
    src/galois.cpp
    src/geometry.cpp
    src/meshes.cpp
    src/noise.cpp
    src/primitives.cpp
    src/rasterization.cpp
    src/rays.cpp
    src/runs.cpp
    src/shards.cpp
    src/spatial.cpp
    src/tensors.cpp
    src/voronoi.cpp
    src/voxels.cpp)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    VoxelooGeometry
    VoxelooLightKernelry
    Voxeloo
    OpenSimplexNoise
    robin_hood::robin_hood
    pybind11::pybind11
    Eigen3::Eigen
    cereal::cereal
    tomasakeninemoeller)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC 
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/../include
)