cmake_minimum_required(VERSION 3.10)

project(Lab_3)

include_directories(include)

set(SOURCES
    src/class_a.cpp
    src/class_b.cpp
    src/class_c.cpp
    src/main.cpp
    src/functions.cpp
    src/menu.cpp
)

set(HEADERS 
    include/class_a.h
    include/class_b.h
    include/class_c.h
    include/functions.h
    include/const.h
    include/menu.h
)

add_executable(Lab_3 ${SOURCES} ${HEADERS})