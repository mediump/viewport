cmake_minimum_required(VERSION 3.5)

project(viewport VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add subdirectories
add_subdirectory(extern)
add_subdirectory(lib)
add_subdirectory(examples)