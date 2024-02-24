set(TEXTURES_DIR ${CMAKE_CURRENT_SOURCE_DIR})

file (GLOB_RECURSE TEXTURES
        ${TEXTURES_DIR}/*.jpg
)

file(COPY ${TEXTURES} DESTINATION ${CMAKE_BINARY_DIR}/textures)

add_custom_target(textures)