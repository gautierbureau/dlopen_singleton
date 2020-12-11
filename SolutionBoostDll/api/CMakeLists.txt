set(api_sources Api.cpp)

set(api_headers Api.hpp)

add_library(api ${LIBRARY_TYPE} ${api_sources})

target_include_directories(api
  INTERFACE
    $<INSTALL_INTERFACE:include>
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  )

target_link_libraries(api PRIVATE common log)

if(LIBRARY_TYPE STREQUAL "SHARED")
  if(MSVC)
    install(TARGETS api DESTINATION bin)
  else()
    install(TARGETS api DESTINATION lib)
  endif()
endif()
