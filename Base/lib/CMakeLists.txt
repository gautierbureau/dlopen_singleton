set(lib_sources LibInstance.cpp)

set(lib_headers Lib.hpp LibInstance.hpp)

add_library(lib SHARED ${lib_sources})
target_link_libraries(lib PUBLIC log)
