cmake_minimum_required(VERSION 3.10)

project(Lab_7)

include_directories(include)

set(SOURCES
    src/main.cpp
    src/car.cpp
    src/binary_file.cpp
    src/menu.cpp
    src/functions.cpp
    src/file_exception.cpp
    src/file_exception_empty.cpp
)

set(HEADERS 
   include/binary_file.h
   include/car.h
   include/const.h
   include/functions.h
   include/menu.h
   include/file_exception.h
   include/file_exception_empty.h

)

add_executable(Lab_7 ${SOURCES})