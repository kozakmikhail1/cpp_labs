cmake_minimum_required(VERSION 3.10)

project(Lab_4)

include_directories(include)

set(SOURCES 
    src/cat.cpp
    src/dog.cpp
    src/human.cpp
    src/animal.cpp
    src/mammal.cpp
    src/main.cpp
    src/functions.cpp
    src/menu.cpp
)

set(HEADERS
    include/cat.h
    include/dog.h
    include/human.h
    include/animal.h
    include/mammal.h
    include/functions.h
    include/menu.h
    include/const.h
)

add_executable(Lab_4 ${SOURCES})