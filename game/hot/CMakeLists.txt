include_directories(${INLUDES_PATH})

add_library(hot SHARED 
    ../shared/interface.h

    ./src/game.h
    ./src/game.c
)

target_link_libraries(hot
    ${LIBS_PATH}/MinGW/libglfw3dll.a
    glad
    opengl32
    gdi32
    user32
    kernel32
    cimgui
)

target_include_directories(hot
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../shared/
)

set_target_properties(hot PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
