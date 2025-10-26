# Set the project name
project (VoxelooGaiaTest)

# Add a library with the above sources
add_executable(${PROJECT_NAME}
    light_test.cpp
    maps_test.cpp
    muck_test.cpp
    stream_test.cpp
    terrain_test.cpp)

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
