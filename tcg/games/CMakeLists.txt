cmake_minimum_required(VERSION 3.1.0)
set (CMAKE_CXX_STANDARD 20)

set(TEXAS_SOURCE_DIR ${CMAKE_SOURCE_DIR}/tcg/games/tex/src)
set(TEXAS_HEADERS_DIR ${CMAKE_SOURCE_DIR}/tcg/games/tex/headers)

add_subdirectory(${TEXAS_SOURCE_DIR})

aux_source_directory(${TEXAS_SOURCE_DIR} TEX_SRCS)

add_library(Texas STATIC ${TEX_SRCS})

target_include_directories(Texas PUBLIC
    ${TEXAS_HEADERS_DIR}
)
target_include_directories(Texas PRIVATE
    ${ENGINE_HEADERS_DIR}
)