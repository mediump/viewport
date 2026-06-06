add_library(v3d_vulkan_rhi STATIC
  VulkanBufferView.hpp
  VulkanDeviceContext.hpp
  VulkanPipelineState.hpp
  VulkanRenderDevice.hpp
  VulkanShaderResourceBinding.hpp
  VulkanSwapChain.hpp
  VulkanTextureView.hpp
  VulkanBufferView.cpp
  VulkanDeviceContext.cpp
  VulkanPipelineState.cpp
  VulkanRenderDevice.cpp
  VulkanShaderResourceBinding.cpp
  VulkanSwapChain.cpp
  VulkanTextureView.cpp
)
target_link_libraries(v3d_vulkan_rhi PRIVATE
  viewport_rhi
  viewport_core
  viewport_window
)