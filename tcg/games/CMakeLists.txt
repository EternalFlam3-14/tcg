cmake_minimum_required(VERSION 3.1.0)
set (CMAKE_CXX_STANDARD 20)

set(TEXAS_SOURCE_DIR ${CMAKE_SOURCE_DIR}/tcg/games/tex/src)
set(TEXAS_HEADERS_DIR ${CMAKE_SOURCE_DIR}/tcg/games/tex/headers)

set(HEMPCEED_SOURCE_DIR ${CMAKE_SOURCE_DIR}/tcg/games/hempceed/src)
set(HEMPCEED_HEADERS_DIR ${CMAKE_SOURCE_DIR}/tcg/games/hempceed/headers)

add_subdirectory(${HEMPCEED_SOURCE_DIR})
add_subdirectory(${TEXAS_SOURCE_DIR})

aux_source_directory(${TEXAS_SOURCE_DIR} TEX_SRCS)
aux_source_directory(${HEMPCEED_SOURCE_DIR} HEMP_SRCS)

add_library(Hemp STATIC ${HEMP_SRCS})
add_library(Texas STATIC ${TEX_SRCS})

target_include_directories(Hemp PUBLIC
    ${HEMPCEED_HEADERS_DIR}
)
target_include_directories(Hemp PRIVATE
    ${ENGINE_HEADERS_DIR}
)

target_include_directories(Texas PUBLIC
    ${TEXAS_HEADERS_DIR}
)
target_include_directories(Texas PRIVATE
    ${ENGINE_HEADERS_DIR}
)