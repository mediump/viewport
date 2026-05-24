add_subdirectory(core)
add_subdirectory(rhi)
add_subdirectory(window)

add_library(viewport INTERFACE)
target_link_libraries(viewport INTERFACE
  viewport_core
  viewport_rhi
  viewport_window
)