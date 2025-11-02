include_directories(${INLUDES_PATH})

add_executable(exe
    ../shared/interface.h
    ../shared/input_def.h

    src/reloading.h
    src/reloading.c
    src/main.c

    src/window/window.h
    src/window/window.c
    src/window/input.h
    src/window/input.c
)

target_link_libraries(exe
    ${LIBS_PATH}/MinGW/libglfw3dll.a
    glad
    opengl32
    gdi32
    user32
    kernel32
)

target_include_directories(exe
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../shared/
)

set_target_properties(exe PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
