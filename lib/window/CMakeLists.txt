add_library(viewport_window STATIC
  Window.cpp
  Window.hpp
  RenderingServer.hpp
  RenderingServer.cpp
  Interface/IWindow.hpp
  Platform/GLFW/GLFWWindow.hpp
  Platform/GLFW/GLFWWindow.cpp
  Platform/GLFW/GLFWRenderingServer.hpp
  Platform/GLFW/GLFWRenderingServer.cpp
  Objects/WindowObjects.hpp
)

target_include_directories(viewport_window PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(viewport_window PRIVATE
  viewport_core
  glfw
)