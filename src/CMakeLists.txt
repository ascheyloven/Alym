file(GLOB_RECURSE FILE_SOURCES RELATIVE_PATH
        ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/*.h
)

add_executable(Main ${FILE_SOURCES})

target_compile_features(Main PRIVATE cxx_std_23)
set_target_properties(Main PROPERTIES CXX_EXTENSIONS off CXX_STANDARD_REQUIRED on)

#if (MSVC)
#    target_compile_options(Main PRIVATE /W4 /Wall /sdl /external:anglebrackets /external:W2 /fsanitize=address)
#    add_compile_options(/MP)
#else ()
#    target_compile_options(Main PRIVATE -Wall -Wextra -Wpedantic -isystem)
#endif ()

find_package(Vulkan REQUIRED)
target_include_directories(Main PRIVATE ${Vulkan_INCLUDE_DIRS})
target_link_libraries(Main Vulkan::Vulkan)


find_package(glm CONFIG REQUIRED)
if (glm_FOUND)
    message(STATUS "GLM FOUND")
    target_include_directories(Main PRIVATE ${glm_INCLUDE_DIRS})
    target_link_libraries(Main ${glm_LIBRARIES} glm::glm)
endif()


find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(Main glfw)

find_package(SDL2 REQUIRED)
if (SDL2_FOUND)
    message(STATUS "SDL2 FOUND")
    target_link_libraries(Main SDL2::SDL2)
endif ()

find_package(imgui CONFIG REQUIRED)
if (imgui_FOUND)
    message(STATUS "IMGUI FOUND")
    target_link_libraries(Main imgui::imgui)
endif ()