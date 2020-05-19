set(common_sources Common.cpp)

set(common_headers Common.hpp)

add_library(common ${LIBRARY_TYPE} ${common_sources})

target_include_directories(common
  INTERFACE
    $<INSTALL_INTERFACE:include>
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  )

target_link_libraries(common PRIVATE log)

if(LIBRARY_TYPE STREQUAL "SHARED")
  if(MSVC)
    install(TARGETS common DESTINATION bin)
  else()
    install(TARGETS common DESTINATION lib)
  endif()
endif()
