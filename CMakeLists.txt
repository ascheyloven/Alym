cmake_minimum_required(VERSION 3.27.8)

project(Alym
        VERSION 1.0
        DESCRIPTION "Alym - Vulkan based Game Engine"
        LANGUAGES CXX)

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR} )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )

add_definitions(-DUNICODE)
add_definitions(-D_UNICODE)

add_subdirectory(src)
add_subdirectory(thirdparty)
add_subdirectory(shaders)
add_subdirectory(textures)

target_link_libraries(Main thirdparty)
