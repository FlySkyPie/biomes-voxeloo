# Set the project name
project (VoxelooAnima)

# Add a library with the above sources
add_library(${PROJECT_NAME} src/find_surfaces.cpp)

include(../cmake/CPM.cmake)

CPMAddPackage("gh:FlySkyPie/biomes-voxeloo-geometry@0.1.1")

target_link_libraries(${PROJECT_NAME} PRIVATE VoxelooGeometry)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC 
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/../
)



# project(subbinary)

# # Create the executable
# add_executable(${PROJECT_NAME} main.cpp)

# # Link the static library from subproject1 using its alias sub::lib1
# # Link the header only library from subproject2 using its alias sub::lib2
# # This will cause the include directories for that target to be added to this project
# target_link_libraries(${PROJECT_NAME}
#     sub::lib1
#     sub::lib2
# )
