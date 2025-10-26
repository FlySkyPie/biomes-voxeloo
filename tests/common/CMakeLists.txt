# Set the project name
project (VoxelooCoreTest)

# Add a library with the above sources
add_executable(${PROJECT_NAME}
    bits_test.cpp
    blocks_bench.cpp
    blocks_test.cpp
    boxifier_test.cpp
    colors_test.cpp
    format_test.cpp
    geometry_test.cpp
    history_test.cpp
    hull_test.cpp
    knn_test.cpp
    quadifier_test.cpp
    rays_test.cpp
    runs_bench.cpp
    runs_test.cpp
    sparse_test.cpp
    spatial_test.cpp
    subbox_test.cpp
    subquad_test.cpp
    succinct_bench.cpp
    succinct_test.cpp
    threads_test.cpp
    utils_test.cpp
    voxels_test.cpp)

include(../../cmake/CPM.cmake)

set(CEREAL_BUILD_DOC OFF)
set(EIGEN_BUILD_DOC OFF)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

CPMAddPackage("gh:FlySkyPie/biomes-voxeloo-geometry@0.1.1")
CPMAddPackage("gh:catchorg/Catch2@3.4.0")
CPMAddPackage("gh:USCiLab/cereal@1.3.2")
CPMAddPackage("gl:libeigen/eigen#3.4.0")
CPMAddPackage("gh:martinus/robin-hood-hashing#3.11.5")

find_package(Catch2 CONFIG REQUIRED) # @catch2

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    VoxelooGeometry
    cereal::cereal
    robin_hood::robin_hood
    Eigen3::Eigen)

target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2WithMain)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    Voxeloo
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC 
    ${PROJECT_SOURCE_DIR}/../../include
)
