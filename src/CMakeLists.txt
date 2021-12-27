set(BINARY ${CMAKE_PROJECT_NAME})

set(CMAKE_CXX_FLAGS_RELEASE "/MT")
set(CMAKE_CXX_FLAGS_DEBUG "/MTd")

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp *.cc)

set(SOURCES ${SOURCES})

set(CMAKE_PROJECT_VERSION "maggus test")
set(CMAKE_PROJECT_VERSION_MAJOR 1)
set(CMAKE_PROJECT_VERSION_MINOR 1)
set(CMAKE_PROJECT_VERSION_PATCH 1)

add_executable(${BINARY}_run ${SOURCES})

add_library(${BINARY}_lib  ${SOURCES})

add_library(nanodbc nanodbc/nanodbc.cpp nanodbc/nanodbc.h)
set(ODBC_LIBRARIES odbc32.lib odbccp32.lib Ws2_32.lib)
target_link_libraries(${BINARY}_run nanodbc ${ODBC_LIBRARIES})
target_link_libraries(${BINARY}_lib nanodbc ${ODBC_LIBRARIES})