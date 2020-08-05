cmake_minimum_required(VERSION 3.0)
project(
    "Zalg"
    VERSION 0.1.0
    DESCRIPTION "A library of data structures and algorithms implemented in C"
    LANGUAGES C
)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

set(SRC
    src/structures/list.c
    src/structures/dynamic_array.c
    src/type.c
)

add_library(zalg STATIC ${SRC})

target_include_directories(zalg
    PRIVATE src
    PUBLIC include
)
target_link_libraries(zalg
    PUBLIC m # C math library
)

add_subdirectory(examples)
