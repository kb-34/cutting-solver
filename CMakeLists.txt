cmake_minimum_required(VERSION 3.2.1)

project(AIM)


set(SOURCES
    ${SOURCES}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

include_directories(${CMAKE_SOURCE_DIR}/headers)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -g -Wextra -pedantic")

add_executable(solver ${SOURCES} ${HEADERS})

set_property(TARGET aim PROPERTY CXX_STANDARD 17)
