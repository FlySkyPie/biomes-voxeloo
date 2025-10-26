# Set the project name
project (VoxelooGaloisTest)

# Add a library with the above sources
add_executable(${PROJECT_NAME}
    galois_test.cpp
    lighting_test.cpp)

include(../../cmake/CPM.cmake)

set(CEREAL_BUILD_DOC OFF)
set(EIGEN_BUILD_DOC OFF)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

CPMAddPackage("gh:FlySkyPie/biomes-voxeloo-geometry@0.1.1")
CPMAddPackage("gh:FlySkyPie/biomes-voxeloo-light-kernelry@0.1.3")
CPMAddPackage("gh:catchorg/Catch2@3.4.0")
CPMAddPackage("gh:USCiLab/cereal@1.3.2")
CPMAddPackage("gl:libeigen/eigen#3.4.0")
CPMAddPackage("gh:martinus/robin-hood-hashing#3.11.5")
CPMAddPackage("gh:FlySkyPie/OpenSimplexNoise@1.0.2")
CPMAddPackage("gh:FlySkyPie/tomasakeninemoeller@1.0.0")

find_package(Catch2 CONFIG REQUIRED) # @catch2

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    VoxelooGeometry
    VoxelooLightKernelry
    cereal::cereal
    robin_hood::robin_hood
    Eigen3::Eigen
    OpenSimplexNoise
    tomasakeninemoeller)

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
