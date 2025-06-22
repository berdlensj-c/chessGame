cmake_minimum_required(VERSION 3.1)
project(Chess)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Use FindSFML (automatically finds the one installed via pacman)
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Include headers
include_directories(include)

# Add source files
file(GLOB SOURCES src/*.cpp)

# Create the executable
add_executable(Chess ${SOURCES})

# Link SFML libraries
target_link_libraries(Chess sfml-graphics sfml-window sfml-system)


