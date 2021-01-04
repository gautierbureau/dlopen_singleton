set(log_sources Log.cpp Util.cpp)

set(log_headers Log.hpp Util.hpp)

add_library(log ${LIBRARY_TYPE} ${log_sources})

target_include_directories(log
  INTERFACE
    $<INSTALL_INTERFACE:include>
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  )

target_link_libraries(log PRIVATE Boost::log)

if(LIBRARY_TYPE STREQUAL "SHARED")
  if(MSVC)
    install(TARGETS log DESTINATION bin)
  else()
    install(TARGETS log DESTINATION lib)
  endif()
endif()
