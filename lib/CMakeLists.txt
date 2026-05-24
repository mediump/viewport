add_subdirectory(rhi)

add_library(viewport INTERFACE)
target_link_libraries(viewport INTERFACE
    viewport_rhi
)