add_library(viewport_window STATIC
  Window.hpp
  Window.cpp
  Interface/IWindow.hpp
  Platform/GLFW/GLFWWindow.hpp
  Platform/GLFW/GLFWWindow.cpp
)

target_include_directories(viewport_window PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(viewport_window PRIVATE
  viewport_core
)