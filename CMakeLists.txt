cmake_minimum_required(VERSION 3.1.0)
set (CMAKE_CXX_STANDARD 20)
project(tcg VERSION 0.1.0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/app)

set(TCG_SOURCE_DIR ${CMAKE_SOURCE_DIR}/tcg/tcg/src)
set(TCG_HEADERS_DIR ${CMAKE_SOURCE_DIR}/tcg/tcg/headers)

set(ENGINE_SOURCE_DIR ${CMAKE_SOURCE_DIR}/engine/src)
set(ENGINE_HEADERS_DIR ${CMAKE_SOURCE_DIR}/engine/headers)

set(ENGINE_LIB_DIR ${CMAKE_SOURCE_DIR}/engine)
set(GAMES_LIB_DIR ${CMAKE_SOURCE_DIR}/tcg/games)

include_directories(
    ${TCG_HEADERS_DIR},
    ${ENGINE_HEADERS_DIR}
)

add_subdirectory(${ENGINE_LIB_DIR})
add_subdirectory(${TCG_SOURCE_DIR})
add_subdirectory(${GAMES_LIB_DIR})

aux_source_directory(${TCG_SOURCE_DIR}  DIR_SRCS)
add_executable(tcg ${DIR_SRCS})

target_include_directories(tcg PUBLIC
    ${TCG_HEADERS_DIR}
)
target_link_libraries(tcg PUBLIC Engine)
target_link_libraries(tcg PUBLIC Texas)
target_link_libraries(tcg PUBLIC Hemp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)