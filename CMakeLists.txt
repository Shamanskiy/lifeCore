cmake_minimum_required(VERSION 3.10)

project(lifeCore
      VERSION 1.0
      DESCRIPTION "Logic core of Conway's Game of Life"
      LANGUAGES CXX)

# set c++ standard
set(CMAKE_CXX_STANDARD 14)

# Let's ensure -std=c++xx instead of -std=g++xx
set(CMAKE_CXX_EXTENSIONS OFF)

# Let's nicely support folders in IDEs
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Download and unpack googletest at configure time
configure_file(${CMAKE_SOURCE_DIR}/external/googletest/CMakeLists.txt.in
${CMAKE_BINARY_DIR}/external/googletest/download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/external/googletest/download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/external/googletest/download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/external/googletest/src
                 ${CMAKE_CURRENT_BINARY_DIR}/external/googletest/build
                 EXCLUDE_FROM_ALL)

# The compiled library code is here
add_subdirectory(src)

# The executable code is here
add_subdirectory(bin)

# Unit tests are here
add_subdirectory(test)

