add_subdirectory(core)
add_subdirectory(rhi)
add_subdirectory(scene)
add_subdirectory(window)

add_library(viewport STATIC
  v3d.hpp
)
target_include_directories(viewport PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}
)
target_link_libraries(viewport PUBLIC
  viewport_core
  viewport_rhi
  viewport_scene
  viewport_window
)