cmake_minimum_required(VERSION 3.12.0)

include_directories(include)

project(lab8)

set(SOURCES
    src/main.cpp
    src/stack_menu.cpp
    src/get_input.cpp
)

set(HEADERS
    include/stack.h
    include/get_input.h
    include/stack_menu.h
    include/stack_iterator.h
    include/stack_algorithms.h
)

add_executable(lab8 ${SOURCES} ${HEADERS})