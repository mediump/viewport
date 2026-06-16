cmake_minimum_required(VERSION 3.5)

project(viewport VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Vulkan)

if(CMAKE_BUILD_TYPE STREQUAL DEBUG)
  add_compile_definitions(V3D_DEBUG=1)
else()
  add_compile_definitions(V3D_DEBUG=0)
endif()

if(WIN32)
  add_compile_definitions(V3D_PLATFORM_WINDOWS=1)
elseif(LINUX)
  add_compile_definitions(V3D_PLATFORM_LINUX=1)
elseif(APPLE)
  add_compile_definitions(V3D_PLATFORM_MACOS=1)
else()
  add_compile_definitions(V3D_PLATFORM_UNKNOWN=1)
endif()

# Add subdirectories
add_subdirectory(extern)
add_subdirectory(lib)
add_subdirectory(examples)
add_subdirectory(tests)
