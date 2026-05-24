add_executable(example_01_hello_triangle
    main.cpp
)

target_link_libraries(example_01_hello_triangle PRIVATE
    viewport
)