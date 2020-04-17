cmake_minimum_required(VERSION 3.14)
project(dlopen_singleton)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(LIBRARY_TYPE SHARED CACHE STRING "Choose either STATIC or SHARED.")

add_subdirectory(log)
add_subdirectory(lib)

add_executable(dlopen_singleton main.cpp)
target_link_libraries(dlopen_singleton PUBLIC log ${CMAKE_DL_LIBS})
target_include_directories(dlopen_singleton PUBLIC lib)