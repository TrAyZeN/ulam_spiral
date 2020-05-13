cmake_minimum_required(VERSION 3.10)

project(
    ulam_spiral
    VERSION 1.0
)
set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})
find_file(SDL2_INCLUDE_DIR NAME SDL.h HINTS SDL2)
find_library(SDL2_LIBRARY NAME SDL2)

file(
    GLOB_RECURSE
    SOURCE_FILES
    src/*
)
file(
    GLOB_RECURSE
    SOURCE_HEADERS
    include/*
)
set(SOURCES ${SOURCE_FILES} ${SOURCE_HEADERS})

add_executable(
    ulam_spiral
    ${SOURCES}
)
target_include_directories(
    ulam_spiral
    PRIVATE
    include/
)
target_include_directories(
    ulam_spiral
    PRIVATE
    ${SDL2_INCLUDE_DIR}
)
file(
    GLOB_RECURSE
    SDL2_LIBRARY_FILES
    ${SDL2_LIBRARY}/*.lib
)
target_link_libraries(
    ulam_spiral
    ${SDL2_LIBRARY_FILES}
)
