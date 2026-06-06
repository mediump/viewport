cmake_minimum_required(VERSION 3.5)

project(viewport VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(${CMAKE_BUILD_TYPE} STREQUAL DEBUG)
  add_compile_definitions(V3D_DEBUG=1)
else()
  add_compile_definitions(V3D_DEBUG=0)
endif()

# Add subdirectories
add_subdirectory(extern)
add_subdirectory(lib)
add_subdirectory(examples)
add_subdirectory(tests)
