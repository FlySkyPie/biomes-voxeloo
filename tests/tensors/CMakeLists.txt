# Set the project name
project (VoxelooTensorsTest)

# Add a library with the above sources
add_executable(${PROJECT_NAME}
    arrays_test.cpp
    buffers_test.cpp
    routines_test.cpp
    succinct_bench.cpp
    succinct_test.cpp
    tensors_test.cpp)

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
CPMAddPackage("gh:martinus/robin-hood-hashing#3.11.5")

find_package(Catch2 CONFIG REQUIRED) # @catch2

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    VoxelooGeometry
    cereal::cereal
    robin_hood::robin_hood)

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
