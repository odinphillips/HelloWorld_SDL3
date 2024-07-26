cmake_minimum_required(VERSION 3.12.0)
project(HelloWorld_SDL3)

find_package(SDL3 CONFIG REQUIRED)

add_executable(helloworld-sdl3
    main.cpp
)

target_link_libraries(helloworld-sdl3 PRIVATE SDL3::SDL3)

set(DLLS_DIR "${CMAKE_SOURCE_DIR}/dlls")

add_custom_target(copy_dlls
    COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different
        "${CMAKE_SOURCE_DIR}/dlls"
        "${CMAKE_BINARY_DIR}"
    COMMENT "Copying dlls to build directory"
)

add_dependencies(helloworld-sdl3 copy_dlls)
