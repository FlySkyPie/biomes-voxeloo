cmake_minimum_required (VERSION 3.5)

project(Voxeloo)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
option(VOXELOO_BUILD_TEST "BUILD TEST LIBRARIES" ON)

# add_library(${PROJECT_NAME} STATIC src/voxeloo.cpp)

include(cmake/CPM.cmake)

CPMAddPackage("gh:FlySkyPie/biomes-voxeloo-geometry@0.1.1")
CPMAddPackage("gh:FlySkyPie/biomes-voxeloo-light-kernelry@0.1.3")
CPMAddPackage("gh:USCiLab/cereal@1.3.2")
CPMAddPackage(
    URI "gl:libeigen/eigen#3.4.0"
    OPTIONS
        "EIGEN_BUILD_DOC OFF"
)
CPMAddPackage(
    NAME zstd
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

find_package(Cereal REQUIRED) # @cereal
find_package(ZSTD REQUIRED)  # @zstd
find_package(Eigen3 REQUIRED) # @eigen
find_package(Threads REQUIRED)

# Add sub directories
add_subdirectory(src/anima)
add_subdirectory(src/common)
add_subdirectory(src/biomes)
add_subdirectory(src/gaia)
add_subdirectory(src/mapping)
add_subdirectory(src/tensors)

# add_subdirectory(py_ext)

add_library(${PROJECT_NAME} STATIC 
    src/voxeloo.cpp
    $<TARGET_OBJECTS:VoxelooAnima>
    $<TARGET_OBJECTS:VoxelooCore>
    $<TARGET_OBJECTS:VoxelooBiomes>
    $<TARGET_OBJECTS:VoxelooGaia>
    $<TARGET_OBJECTS:VoxelooMapping>
    $<TARGET_OBJECTS:VoxelooTensors>
)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    VoxelooGeometry
    VoxelooLightKernelry
    zstd
    cereal::cereal
    robin_hood::robin_hood
    Eigen3::Eigen
    prometheus-cpp::push
)

# set_target_properties(${PROJECT_NAME} PROPERTIES CXX_VISIBILITY_PRESET "hidden")

if(VOXELOO_BUILD_TEST)
    enable_testing()
    add_subdirectory(tests/biomes)
    add_subdirectory(tests/common)
    add_subdirectory(tests/gaia)
    add_subdirectory(tests/galois)
    add_subdirectory(tests/tensors)
endif()
