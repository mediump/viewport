add_library(viewport_core STATIC
  Interface/IContextObject.hpp
  Interface/IContextObject.cpp
  Interface/IServer.hpp
  Interface/ISingleton.hpp
  Log/Log.hpp
  Log/Log.cpp
)

target_include_directories(viewport_core PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(viewport_core PUBLIC
  spdlog
)