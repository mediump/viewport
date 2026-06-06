add_library(viewport_core STATIC
  Context.hpp
  Context.cpp
  Interface/IContextObject.hpp
  Interface/IContextObject.cpp
  Interface/IServer.hpp
  Interface/ISingleton.hpp
  Log/Log.hpp
  Log/Log.cpp
  Objects/ErrorCodes.hpp
  Objects/Settings.hpp
)

target_include_directories(viewport_core PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(viewport_core PUBLIC
  viewport_scene
  viewport_window
  spdlog
)

add_subdirectory(Private)
target_link_libraries(viewport_core PRIVATE
  viewport_core_pr
)