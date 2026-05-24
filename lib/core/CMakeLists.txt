add_library(viewport_core STATIC
  Interface/IContextObject.hpp
  Interface/IContextObject.cpp
)

target_include_directories(viewport_core PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)