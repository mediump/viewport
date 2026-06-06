add_subdirectory(Platform/Vulkan)

add_library(viewport_rhi STATIC
  Interface/IBufferView.hpp
  Interface/IDeviceContext.hpp
  Interface/IPipelineState.hpp
  Interface/IRenderDevice.hpp
  Interface/IShaderResourceBinding.hpp
  Interface/ISwapChain.hpp
  Interface/ITextureView.hpp
  Interface/ITexture.hpp
  Interface/IBuffer.hpp
  Interface/IShader.hpp
  Interface/IResourceAllocator.hpp
  Objects/PlatformObjects.hpp
)
set_target_properties(viewport_rhi PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(viewport_rhi PRIVATE
  v3d_vulkan_rhi
)

target_include_directories(viewport_rhi PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)