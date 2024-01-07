cmake_minimum_required(VERSION 3.28)
project(Alym VERSION 0.1)

#Enable multithreaded builds
add_compile_options(/MP)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(DCMAKE_GENERATOR_PLATFORM "x64")
set(CMAKE_CXX_EXTENSIONS OFF)
set(VCPKG_POLICY_EMPTY_PACKAGE enabled)

add_definitions(-DUNICODE)
add_definitions(-D_UNICODE)

file(GLOB_RECURSE FILE_SOURCES RELATIVE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h
)

add_executable(${PROJECT_NAME} ${FILE_SOURCES})

find_package(Vulkan REQUIRED)
target_include_directories(${PROJECT_NAME} PUBLIC ${Vulkan_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} Vulkan::Vulkan)


find_package(glm CONFIG REQUIRED)
if (glm_FOUND)
    message(STATUS "GLM FOUND")
    target_include_directories(${PROJECT_NAME} PRIVATE ${glm_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} ${glm_LIBRARIES} glm::glm)
endif()


find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} glfw)

find_package(imgui CONFIG REQUIRED)
if (imgui_FOUND)
    message(STATUS "IMGUI FOUND")
    target_link_libraries(${PROJECT_NAME} imgui::imgui)
endif ()