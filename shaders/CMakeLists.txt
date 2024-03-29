find_package(Vulkan REQUIRED COMPONENTS glslc)
find_program(glslc_executable NAMES glslc HINTS Vulkan::glslc)

set(SHADER_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(SHADER_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR})

file(GLOB SHADERS
        ${SHADER_SOURCE_DIR}/*.vert
        ${SHADER_SOURCE_DIR}/*.frag
        ${SHADER_SOURCE_DIR}/*.comp
        ${SHADER_SOURCE_DIR}/*.geom
        ${SHADER_SOURCE_DIR}/*.tesc
        ${SHADER_SOURCE_DIR}/*.tese
        ${SHADER_SOURCE_DIR}/*.mesh
        ${SHADER_SOURCE_DIR}/*.task
        ${SHADER_SOURCE_DIR}/*.rgen
        ${SHADER_SOURCE_DIR}/*.rchit
        ${SHADER_SOURCE_DIR}/*.rmiss)

add_custom_command(
        COMMAND ${CMAKE_COMMAND} -E make_directory ${SHADER_BINARY_DIR}
        OUTPUT ${SHADER_BINARY_DIR}
        COMMENT "Creating ${SHADER_BINARY_DIR}"
)

foreach(source IN LISTS SHADERS)
    get_filename_component(FILENAME ${source} LAST_EXT)
    string(REPLACE "." "" FILE_EXT ${FILENAME})
    add_custom_command(
            OUTPUT ${SHADER_BINARY_DIR}/${FILE_EXT}.spv
            DEPENDS ${source}
            COMMAND ${glslc_executable} ${source} -o ${SHADER_BINARY_DIR}/${FILE_EXT}.spv
            COMMENT "Compiling to ${SHADER_BINARY_DIR}/${FILE_EXT}.spv"
    )
    list(APPEND SPV_SHADERS ${SHADER_BINARY_DIR}/${FILE_EXT}.spv)
endforeach()

add_custom_target(shaders ALL DEPENDS ${SPV_SHADERS})
