set(BINARY ${CMAKE_PROJECT_NAME})

set(CMAKE_CXX_FLAGS_RELEASE "/MT")
set(CMAKE_CXX_FLAGS_DEBUG "/MTd")

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp *.cc)

set(SOURCES ${SOURCES})

add_executable(${BINARY}_run ${SOURCES})

add_library(${BINARY}_lib  ${SOURCES})