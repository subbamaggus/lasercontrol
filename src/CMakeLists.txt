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
target_link_libraries(${BINARY}_run nanodbc ${ODBC_LIBRARIES})
target_link_libraries(${BINARY}_run open62541)
target_link_libraries(${BINARY}_run ws2_32 wsock32)

add_executable(${BINARY}_snr ${SOURCES} ${CMAKE_CURRENT_SOURCE_DIR}/main_snr.cpp)
target_link_libraries(${BINARY}_snr nanodbc ${ODBC_LIBRARIES})
target_link_libraries(${BINARY}_snr open62541)
target_link_libraries(${BINARY}_snr ws2_32 wsock32)

add_library(${BINARY}_lib  ${SOURCES} ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
target_link_libraries(${BINARY}_lib nanodbc ${ODBC_LIBRARIES})
target_link_libraries(${BINARY}_lib open62541)
target_link_libraries(${BINARY}_lib ws2_32 wsock32)

