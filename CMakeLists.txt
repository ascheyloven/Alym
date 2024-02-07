cmake_minimum_required(VERSION 3.27.8)

project(Alym
        VERSION 1.0
        DESCRIPTION "Alym - Vulkan based Game Engine"
        LANGUAGES CXX)


add_definitions(-DUNICODE)
add_definitions(-D_UNICODE)

add_subdirectory(src)
add_subdirectory(thirdparty)
add_subdirectory(shaders)
target_link_libraries(Main thirdparty)
