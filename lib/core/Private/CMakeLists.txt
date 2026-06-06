add_library(viewport_core_pr STATIC
    ContextPrivate.hpp
    ContextPrivate.cpp
)
target_include_directories(viewport_core_pr PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)
target_link_libraries(viewport_core_pr PRIVATE
    viewport_core
    viewport_rhi
    viewport_scene
    viewport_window
)