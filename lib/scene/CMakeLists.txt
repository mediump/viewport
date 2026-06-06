add_library(viewport_scene STATIC
    Scene.hpp
    Scene.cpp
)

target_include_directories(viewport_scene PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(viewport_scene PRIVATE
    viewport_core
)