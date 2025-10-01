cmake_minimum_required(VERSION 3.20)
project(rover-on-mars LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Only keep Debug and Release
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "" FORCE)

# Sources
set(SOURCES
    src/main.cpp
    src/mars.cpp
    src/rover.cpp
    src/types.cpp
)

set(HEADERS
    src/mars.h
    src/rover.h
    src/types.h
)

add_executable(rover-on-mars ${SOURCES} ${HEADERS})
target_compile_definitions(rover-on-mars PRIVATE ROVER_ON_MARS_BUILD)

# Output path
set_target_properties(rover-on-mars PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/rover-on-mars
)
