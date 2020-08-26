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

# The compiled library code is here
add_subdirectory(src)

# The executable code is here
add_subdirectory(bin)

