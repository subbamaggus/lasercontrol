if(CMAKE_CXX_COMPILER_LOADED)
  message(STATUS "Compiler path: ${CMAKE_CXX_COMPILER}")
  message(STATUS "Compiler ID: ${CMAKE_CXX_COMPILER_ID}")
  message(STATUS "Compiler version: ${CMAKE_CXX_COMPILER_VERSION}")
  message(STATUS "Compiler is part of GCC: ${CMAKE_COMPILER_IS_GNUCXX}")
endif()
   
cmake_minimum_required(VERSION 2.8)
project(app_project)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS_RELEASE "/MT")
set(CMAKE_CXX_FLAGS_DEBUG "/MTd")

include_directories(src)

add_subdirectory(src)
add_subdirectory(tst)
add_subdirectory(lib/googletest)

