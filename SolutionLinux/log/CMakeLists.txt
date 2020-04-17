set(log_sources Log.cpp)

set(log_headers log.hpp)

add_library(log ${LIBRARY_TYPE} ${log_sources})

target_include_directories(log
  INTERFACE
    $<INSTALL_INTERFACE:include>
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  )