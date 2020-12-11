set(lib-common_sources Lib.cpp)

set(lib-common_headers Lib.hpp)

add_library(lib-common ${LIBRARY_TYPE} ${lib-common_sources})

target_include_directories(lib-common
  INTERFACE
    $<INSTALL_INTERFACE:include>
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  )

target_link_libraries(lib-common PRIVATE common api log)

if(LIBRARY_TYPE STREQUAL "SHARED")
  if(MSVC)
    install(TARGETS lib-common DESTINATION bin)
  else()
    install(TARGETS lib-common DESTINATION lib)
  endif()
endif()