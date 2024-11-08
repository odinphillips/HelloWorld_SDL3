cmake_minimum_required(VERSION 3.12.0)
project(HelloWorld_SDL3)

find_package(SDL3 CONFIG REQUIRED)

add_executable(helloworld-sdl3
    main.cpp
)

target_link_libraries(helloworld-sdl3 PRIVATE SDL3::SDL3)

file(GLOB DLLS "${CMAKE_SOURCE_DIR}/dlls/*.dll")

add_custom_target(copy_dlls
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${DLLS}
        "${CMAKE_BINARY_DIR}"
    COMMENT "Copying dlls to build directory"
)

add_dependencies(helloworld-sdl3 copy_dlls)

# This is safe to set on all platforms. Otherwise your SDL app will
#  have a terminal window pop up with it on Windows.
set_property(TARGET helloworld-sdl3 PROPERTY WIN32_EXECUTABLE TRUE)
