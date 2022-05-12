set(BINARY ${CMAKE_PROJECT_NAME})

set(CMAKE_CXX_FLAGS_RELEASE "/MT")
set(CMAKE_CXX_FLAGS_DEBUG "/MTd")

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp *.cc *.c)

get_filename_component(main ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp ABSOLUTE)
list(REMOVE_ITEM SOURCES ${main})
get_filename_component(main ${CMAKE_CURRENT_SOURCE_DIR}/main_snr.cpp ABSOLUTE)
list(REMOVE_ITEM SOURCES ${main})

set(SOURCES ${SOURCES})

set(CMAKE_PROJECT_VERSION "maggus test")
set(CMAKE_PROJECT_VERSION_MAJOR 1)
set(CMAKE_PROJECT_VERSION_MINOR 1)
set(CMAKE_PROJECT_VERSION_PATCH 1)


add_library(nanodbc nanodbc/nanodbc.cpp nanodbc/nanodbc.h)
set(ODBC_LIBRARIES odbc32.lib odbccp32.lib Ws2_32.lib)

add_library(open62541 open62541/open62541.c open62541/open62541.h)


add_executable(${BINARY}_run ${SOURCES} ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
add_executable(${BINARY}_snr ${SOURCES} ${CMAKE_CURRENT_SOURCE_DIR}/main_snr.cpp)
add_library(${BINARY}_lib  ${SOURCES} ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

FOREACH(MODUL "_run" "_snr" "_lib")
  # later make them a dll
  target_link_libraries(${BINARY}${MODUL} nanodbc ${ODBC_LIBRARIES})
  target_link_libraries(${BINARY}${MODUL} open62541)
  target_link_libraries(${BINARY}${MODUL} ws2_32 wsock32)
ENDFOREACH()