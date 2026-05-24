add_library(viewport_rhi STATIC
    Interface/IBufferView.hpp  
    Interface/IBufferView.cpp
    Interface/IDevice.hpp
    Interface/IDevice.cpp
    Interface/IPipelineState.hpp
    Interface/IPipelineState.cpp
    Interface/IShaderResourceBinding.hpp
    Interface/IShaderResourceBinding.cpp
    Interface/ISwapChain.hpp
    Interface/ISwapChain.cpp
    Interface/ITextureView.hpp
    Interface/ITextureView.cpp
)

target_include_directories(viewport_rhi
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/Interface
)