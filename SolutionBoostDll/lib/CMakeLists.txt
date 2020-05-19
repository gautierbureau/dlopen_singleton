set(lib_sources LibInstance.cpp)

set(lib_headers Lib.hpp LibInstance.hpp)

add_library(lib MODULE ${lib_sources})

target_include_directories(lib
  INTERFACE
    $<INSTALL_INTERFACE:include>
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  )

target_link_libraries(lib PRIVATE $<TARGET_FILE:common>)
target_include_directories(lib PRIVATE $<TARGET_PROPERTY:common,INTERFACE_INCLUDE_DIRECTORIES>)

if(LIBRARY_TYPE STREQUAL "STATIC")
  target_include_directories(lib PUBLIC $<TARGET_PROPERTY:log,INTERFACE_INCLUDE_DIRECTORIES>)
  if(MSVC OR APPLE)
    target_link_libraries(lib PRIVATE dlopen_singleton)
  endif()
else()
  target_link_libraries(lib PRIVATE log)
endif()

set_target_properties(lib PROPERTIES PREFIX "")
if(APPLE)
  set_target_properties(lib PROPERTIES SUFFIX ".dylib")
endif()

install(TARGETS lib DESTINATION bin)