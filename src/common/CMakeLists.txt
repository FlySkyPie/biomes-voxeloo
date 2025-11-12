cmake_minimum_required(VERSION 3.16)
project(VoxelooCore CXX)

add_library(
    ${PROJECT_NAME} 
    OBJECT
    boxifier.cpp
    errors.cpp
    frustum.cpp
    hull.cpp
    knn.cpp
    metrics.cpp
    quadifier.cpp
    rays.cpp
    subbox.cpp
    subquad.cpp
    succinct.cpp
    transport.cpp)

include(../../cmake/CPM.cmake)

set(CEREAL_BUILD_DOC OFF)
set(EIGEN_BUILD_DOC OFF)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

CPMAddPackage("gh:FlySkyPie/biomes-voxeloo-geometry@0.1.1")
CPMAddPackage("gh:FlySkyPie/biomes-voxeloo-light-kernelry@0.1.3")
CPMAddPackage("gh:USCiLab/cereal@1.3.2")
CPMAddPackage("gl:libeigen/eigen#3.4.0")
CPMAddPackage(
    # NAME zstd
    GITHUB_REPOSITORY facebook/zstd
    GIT_TAG v1.5.7
    SYSTEM YES
    EXCLUDE_FROM_ALL YES
    SOURCE_SUBDIR build/cmake
    OPTIONS
        "ZSTD_BUILD_STATIC ON"
        "ZSTD_BUILD_SHARED OFF"
        "ZSTD_LEGACY_SUPPORT OFF"
        "ZSTD_BUILD_PROGRAMS OFF"
        "ZSTD_BUILD_CONTRIB OFF"
        "ZSTD_BUILD_TESTS OFF"
)
CPMAddPackage("gh:martinus/robin-hood-hashing#3.11.5")
CPMAddPackage("gh:jupp0r/prometheus-cpp@1.0.1")

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    VoxelooGeometry
    VoxelooLightKernelry
    cereal::cereal
    robin_hood::robin_hood
    Eigen3::Eigen
    prometheus-cpp::push
    libzstd_static)

target_include_directories( ${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/../../include
)
