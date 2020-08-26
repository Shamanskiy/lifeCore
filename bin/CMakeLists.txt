# create a target to build
add_executable(life life.cpp)

# link necessary external libraries and the project library
target_link_libraries(life PRIVATE lifeCore)

# provide paths to include files
target_include_directories(life PRIVATE "${PROJECT_SOURCE_DIR}/src")
