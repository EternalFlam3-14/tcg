cmake_minimum_required(VERSION 3.1.0)
set (CMAKE_CXX_STANDARD 20)

set(ENGINE_SOURCE_DIR ${CMAKE_SOURCE_DIR}/engine/src)
set(ENGINE_HEADERS_DIR ${CMAKE_SOURCE_DIR}/engine/headers)

add_subdirectory(${ENGINE_SOURCE_DIR})

aux_source_directory(${ENGINE_SOURCE_DIR}  ENG_SRCS)

add_library(Engine STATIC ${ENG_SRCS})

include_directories(
    ${ENGINE_SOURCE_DIR},
    ${ENGINE_HEADERS_DIR}
)

