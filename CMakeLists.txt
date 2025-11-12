cmake_minimum_required (VERSION 3.5)

project(
    Voxeloo
    VERSION 0.1.0
    LANGUAGES CXX)

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
    GITHUB_REPOSITORY facebook/zstd
    GIT_TAG v1.5.7
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
CPMAddPackage(
    NAME OpenSimplexNoise
    GITHUB_REPOSITORY "FlySkyPie/OpenSimplexNoise"
    GIT_TAG v1.0.3
    OPTIONS 
        "OSN_BUILD_STATIC ON"
        "OSN_BUILD_SHARED OFF"
)
CPMAddPackage("gh:FlySkyPie/tomasakeninemoeller@1.0.0")

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
    PUBLIC
    VoxelooGeometry
    cereal::cereal
    robin_hood::robin_hood
    OpenSimplexNoise
    Eigen3::Eigen
    tomasakeninemoeller

    PRIVATE
    VoxelooLightKernelry
    libzstd_static
    prometheus-cpp::push
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

install(
    DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    FILES_MATCHING PATTERN "*.hpp"
)

install(
    TARGETS ${PROJECT_NAME} cereal
    EXPORT ${PROJECT_NAME}Targets
)

install(
    EXPORT ${PROJECT_NAME}Targets
    FILE ${PROJECT_NAME}Targets.cmake
    NAMESPACE ${PROJECT_NAME}::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME})


# set_target_properties(${PROJECT_NAME} PROPERTIES CXX_VISIBILITY_PRESET "hidden")

if(VOXELOO_BUILD_TEST)
    enable_testing()
    add_subdirectory(tests/biomes)
    add_subdirectory(tests/common)
    add_subdirectory(tests/gaia)
    add_subdirectory(tests/galois)
    add_subdirectory(tests/tensors)
endif()
