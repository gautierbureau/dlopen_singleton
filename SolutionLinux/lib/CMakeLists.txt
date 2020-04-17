set(lib_sources LibInstance.cpp)

set(lib_headers Lib.hpp LibInstance.hpp)

add_library(lib SHARED ${lib_sources})
target_include_directories(lib PUBLIC $<TARGET_PROPERTY:log,INTERFACE_INCLUDE_DIRECTORIES>)
