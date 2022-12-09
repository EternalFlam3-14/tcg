cmake_minimum_required(VERSION 3.1.0)
set (CMAKE_CXX_STANDARD 20)
project(tcg VERSION 0.1.0)

set(TCG_SOURCE_DIR "src")
set(TCG_HEADERS_DIR "headers")
set(ENGINE_LIB_DIR "engine")
set(ENGINE_SOURCE_DIR "engine/src")
set(ENGINE_HEADERS_DIR "engine/headers")

add_subdirectory(${TCG_SOURCE_DIR})
add_subdirectory(${ENGINE_LIB_DIR})

include_directories(
    ${TCG_SOURCE_DIR}
    ${TCG_HEADERS_DIR}
    ${ENGINE_SOURCE_DIR}
    ${ENGINE_HEADERS_DIR}
)

aux_source_directory(${TCG_SOURCE_DIR}  DIR_SRCS)
add_executable(tcg ${DIR_SRCS})

target_link_directories(tcg PUBLIC engine/headers)
target_link_libraries(tcg Engine)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)