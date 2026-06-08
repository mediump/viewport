add_subdirectory(
    ${CMAKE_SOURCE_DIR}/extern/Catch2 
    ${CMAKE_CURRENT_BINARY_DIR}/Catch2
)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)

add_executable(viewport_tests
    core/AppContextTests.cpp
    core/MathTests.cpp
)

target_link_libraries(viewport_tests PRIVATE
    viewport
    Catch2::Catch2WithMain
)

include(CTest)
include(Catch)
catch_discover_tests(viewport_tests)