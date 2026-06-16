add_subdirectory(glfw)
add_subdirectory(spdlog)

set(V3D_EXTERN_LIB
  glfw
  ${GLFW_LIBRARIES}
  spdlog
  Vulkan::Vulkan
  PARENT_SCOPE
)