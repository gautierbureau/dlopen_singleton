cmake_minimum_required(VERSION 3.9.6 FATAL_ERROR)

if(POLICY CMP0074)
  cmake_policy(SET CMP0074 NEW)
endif()

if(${CMAKE_VERSION} VERSION_GREATER "3.15.0")
  if(POLICY CMP0091)
    cmake_policy(SET CMP0091 NEW)
  endif()
endif()

project(dlopen_singleton)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(LIBRARY_TYPE SHARED CACHE STRING "Choose either STATIC or SHARED.")
set(MSVC_STATIC_RUNTIME_LIBRARY OFF CACHE BOOL "Choose either ON or OFF.")

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)    # export all symbols from dll on Windows
if(LIBRARY_TYPE STREQUAL "STATIC")
  set(CMAKE_ENABLE_EXPORTS ON)                # export all symbols from exe on Windows
endif()

if(UNIX)
  if(LIBRARY_TYPE STREQUAL "SHARED")
    set(CMAKE_SKIP_BUILD_RPATH FALSE)
    set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
    set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
    set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
  endif()
endif()

if(MSVC)
  add_definitions(-D_CRT_SECURE_NO_WARNINGS -D_SCL_SECURE_NO_WARNINGS -D_WIN32_WINNT=0x0601)
  add_definitions(-DLANG_CXX11)
  add_definitions(-bigobj)

  if(LIBRARY_TYPE STREQUAL "STATIC")
    if(MSVC_STATIC_RUNTIME_LIBRARY)
      set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    endif()
  endif()
endif()

set(Boost_NO_SYSTEM_PATHS TRUE)
if(LIBRARY_TYPE STREQUAL "STATIC")
  set(Boost_USE_STATIC_LIBS TRUE)
else()
  set(BUILD_SHARED_LIBS ON)
  add_definitions(-DBOOST_ALL_DYN_LINK)
endif()
if (Boost_USE_STATIC_LIBS)
  if(MSVC_STATIC_RUNTIME_LIBRARY)
    set(Boost_USE_STATIC_RUNTIME True)
  else()
    set(Boost_USE_STATIC_RUNTIME False)
  endif()
endif()
add_definitions(-DBOOST_ALL_NO_LIB)

find_package(Boost 1.70.0 REQUIRED
  COMPONENTS
    log
    log_setup
    filesystem
  NO_CMAKE_PATH
  )

add_subdirectory(log)
add_subdirectory(lib)

add_executable(dlopen_singleton main.cpp main_exports.def)
add_dependencies(dlopen_singleton log)

target_link_libraries(dlopen_singleton PRIVATE ${CMAKE_DL_LIBS})
target_link_libraries(dlopen_singleton PRIVATE Boost::filesystem)

if(LIBRARY_TYPE STREQUAL "STATIC")
  if(MSVC)
    target_link_libraries(dlopen_singleton PRIVATE "-DEF:${CMAKE_CURRENT_SOURCE_DIR}/main_exports.def")
    #target_link_libraries(dlopen_singleton PRIVATE "-WHOLEARCHIVE:$<TARGET_FILE:log>")
    #target_link_libraries(dlopen_singleton PRIVATE $<TARGET_PROPERTY:log,LINK_LIBRARIES>)
    target_link_libraries(dlopen_singleton PRIVATE log)
  elseif(APPLE)
    #target_link_libraries(dlopen_singleton PRIVATE "-force_load" log)
    target_link_libraries(dlopen_singleton PRIVATE log)
  else()
    #target_link_libraries(dlopen_singleton PRIVATE "-Wl,--whole-archive" log "-Wl,--no-whole-archive")
    target_link_libraries(dlopen_singleton PRIVATE log)
  endif()
else()
  target_link_libraries(dlopen_singleton PRIVATE log)
endif()

target_include_directories(dlopen_singleton PRIVATE $<TARGET_PROPERTY:lib,INTERFACE_INCLUDE_DIRECTORIES>)

if(NOT MSVC)
  if(LIBRARY_TYPE STREQUAL "STATIC")
    target_link_options(dlopen_singleton PUBLIC "-rdynamic")
  endif()
endif()

install(TARGETS dlopen_singleton DESTINATION bin)

