cmake_minimum_required(VERSION 3.10)

project(Lab_3)

include_directories(include)

set(SOURCES
    src/class_abc.cpp
    src/main.cpp
    src/functions.cpp
    src/menu.cpp
)

set(HEADERS 
    include/class_abc.h
    include/functions.h
    include/const.h
    include/menu.h
)

add_executable(Lab_3 ${SOURCES} ${HEADERS})