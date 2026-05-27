add_subdirectory(glfw)
add_subdirectory(spdlog)

set(V3D_EXTERN_LIB
  glfw
  spdlog
  PARENT_SCOPE
)